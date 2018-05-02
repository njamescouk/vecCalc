// Line.h
#ifndef have_Line
#define have_Line

#include <string>
#include "PosVector.h"

class Line
{
    PosVector m_from,
              m_to;

public:
    Line() {}

    Line(PosVector from, PosVector to)
        : m_from(from)
        , m_to(to)
    {}
    
    virtual ~Line(){}

    bool operator==(Line l)
    {
        return m_from == l.m_from && m_to == l.m_to;
    }

    /* scalar product */
    double operator*(Line l)
    {
        PosVector pv1(m_from - m_to);
        PosVector pv2(l.m_from - l.m_to);
        return pv1 * pv2;
    }

    PosVector getFrom()
    {
        return m_from;
    }

    PosVector getTo()
    {
        return m_to;
    }

    double xExtent()
    {
        return m_to.x() - m_from.x();
    }

    double yExtent()
    {
        return m_to.y() - m_from.y();
    }

    /* 
        compute deltaX, deltaY such that
        deltaX^2 + deltaY^2 = d^2

        deltaX = d * xSF
        deltaY = d * ySF

        deltaY/deltaX = d * ySF/d * xSF
        grad = ySF/xSF
        ySF = xSF * grad                   1/

        deltaX^2 + deltaY^2 = d^2
        (d * xSF)^2 + (d * ySF)^2 = d^2
        xSF^2 + ySF^2 = 1                  2/

        1/ into 2/
        xSF^2 + xSF^2 * grad^2 = 1
        xSF^2 * (1 + grad^2) = 1
        xSF = 1/sqrt(1 + grad^2)           3/

        3/ into 1/
        ySF = grad/sqrt(1 + grad^2)        4/

        if gradient -ve, deltaY is -ve
    */
    void delta(double d, double &deltaX, double &deltaY)
    {
        double grad = gradient();

        /* vertical, deltaX is 0, deltaY takes sign of grad */
        if (fabs(grad) > 1e6)
        {
            deltaX = 0;
            deltaY = _copysign(d, grad);
        }
        else /* not vertical */
        {
            double xSF = 1/sqrt(1 + grad*grad);
            double ySF = grad/sqrt(1 + grad*grad);

            deltaX = d * xSF;
            deltaY = d * ySF;
        }
    }

    double gradient()
    {
        double deltaX = m_to.x() - m_from.x();
        double deltaY = m_to.y() - m_from.y();

        if (fabs(deltaX) < DBL_EPSILON)
        {
            if (deltaY > 0)
                return .9*DBL_MAX;

            return -.9*DBL_MAX;
        }

        return deltaY/deltaX;
    }

    std::string gradientString()
    {
        double deltaX = m_to.x() - m_from.x();
        double deltaY = m_to.y() - m_from.y();

        if (fabs(deltaX) < DBL_EPSILON)
        {
            if (deltaY > 0)
                return "vertical";

            return "-vertical";
        }

        char buf[BUFSIZ];
        sprintf(buf, "%.2f", deltaY/deltaX);

        return buf;
    }

    /*
        return value of y when x = 0

        y = gradient() * x + c
        c = y - gradient() * x
    */
    double intercept()
    {
        double res = m_to.y() - (gradient() * m_to.x());

        return res;
    }

    std::string interceptString()
    {
        double d = intercept();
        if (fabs(d) > DBL_MAX)
            return "undefined";

        char buf[BUFSIZ];
        sprintf(buf, "%.2f", d);

        return buf;
    }

    PosVector bisect()
    {
        PosVector res = m_from.bisect(m_to);

        return res;
    }

    Line translate(double x, double y)
    {
        PosVector to = m_to.translate(x, y);
        PosVector from = m_from.translate(x, y);
        Line res(from, to);

        return res;
    }

    double length()
    {
        return m_from.distance(m_to);
    }

    bool isParallel(Line l)
    {
        if (*this == l)
            return true;
    
        double g1 = gradient();
        double g2 = l.gradient();
        return (fabs(g1 - g2) < 1e-3);
    }

    PosVector intersect(Line l)
    {
        double thisGrad = gradient();
        double lGrad = l.gradient();

        if (fabs(thisGrad - lGrad) < DBL_EPSILON)
        {
            /* parallel lines meet at infinity */
            return PosVector(DBL_MAX, DBL_MAX);
        }

        if (fabs(thisGrad) > 1e9)
        {
            /* *this is vertical so eqn of *this is x=xInter */
            double xInter = m_from.x(); // or m_to.x() should be the same
            PosVector a = l.suchThatXequals(xInter);
            return a;
        }

        if (fabs(lGrad) > 1e9)
        {
            /* l is vertical so eqn of l is x=xInter */
            double xInter = l.getFrom().x(); // or m_to.x() should be the same
            PosVector a = suchThatXequals(xInter);
            return a;
        }

        double thisIntercept = intercept();
        double lIntercept = l.intercept();
        /*
            yIntercept = thisGrad * xIntercept + thisIntercept (1)
            yIntercept = lGrad * xIntercept + lIntercept       (2)

            equate (1) & (2)
            (thisGrad * xIntercept) - (lGrad * xIntercept) = lIntercept - thisIntercept
            (thisGrad - lGrad)*xIntercept = lIntercept - thisIntercept
            xIntercept = (lIntercept - thisIntercept)/(thisGrad - lGrad)

            from (1)
            yIntercept = thisGrad * xIntercept + thisIntercept

        */
        double xIntercept = (lIntercept - thisIntercept)/(thisGrad - lGrad);
        double yIntercept = thisGrad * xIntercept + thisIntercept;

        return PosVector(xIntercept, yIntercept);
    }

    /* return a line perpendicular to *this through p */
    Line perpendicular(PosVector p)
    {
        PosVector zero(0,0);
        PosVector to(yExtent(), -xExtent()); 
        /* 
            zero - to is perp to *this and same magnitude 
            now move it to p
        */
        Line lPerp(zero.translate(p.x(), p.y()), to.translate(p.x(), p.y()));

        /* now move midpoint to p */
        PosVector pvBis = lPerp.bisect();
        Line toMid(p, pvBis);
        Line lTrans = lPerp.translate(-toMid.xExtent(), -toMid.yExtent());

        return lTrans;
    }

    /* return a line parallel to *this though p */
    Line parallel(PosVector p)
    {
        PosVector pvBis = bisect();
        PosVector delta = pvBis - p; // operator- iffy?

        Line res = translate(-delta.x(), -delta.y());

        return res;
    }

    /*    return *this extended by d at both ends  */
    Line extend(double d)
    {
        double deltaX = 0.0;
        double deltaY = 0.0;
        delta(d, deltaX, deltaY);

        // add delta to xMost, subtract delta from minusXMost
        // which is which?
        PosVector xMost = m_to;
        PosVector minusXMost = m_from;
        if (m_from.x() > m_to.x())
        {
            xMost = m_from;
            minusXMost = m_to;
        }

        /* add delta to to, subract from from */
        PosVector newTo(xMost.x()+deltaX, xMost.y()+deltaY);
        PosVector newFrom(minusXMost.x()-deltaX, minusXMost.y()-deltaY);

        return Line(newFrom, newTo);
    }

    /*
        return *this moved along it's gradient by d

        +ve d => increase rightmost end, or topmost if vertical 
    */
    Line slide(double d)
    {
        double grad = gradient();
        double deltaX = 0.0;
        double deltaY = 0.0;
        delta (d, deltaX, deltaY);

        PosVector businessEnd = m_to;
        PosVector constantEnd = m_from;
        if (m_to < m_from)
        {
            businessEnd = m_from;
            constantEnd = m_to;
        }

        PosVector newFrom(constantEnd.x()+deltaX, constantEnd.y()+deltaY);
        PosVector newTo(businessEnd.x()+deltaX, businessEnd.y()+deltaY);

        return Line(newFrom, newTo);
    }

    void getMaxMin(double &minWidth, double &minHeight, double &maxWidth, double &maxHeight)
    {
        m_from.getMaxMin(minWidth, minHeight, maxWidth, maxHeight);
        m_to.getMaxMin(minWidth, minHeight, maxWidth, maxHeight);
    }

    std::string toPath()
    {
        return m_from.toPath() + " " + m_to.toPath();
    }

    std::string toReversePath()
    {
        return m_to.toPath() + " " + m_from.toPath();
    }

    std::string toString()
    {
        std::string res = m_from.toString() + "," + m_to.toString();
        char buf[BUFSIZ];
        sprintf(buf, 
                ", length: %.2f, m: %s, c: %s", 
                length(), 
                gradientString().c_str(), 
                interceptString().c_str());
        res += buf;

        return res;
    }

    /*
        return unit vector in direction of *this
    */
    PosVector pvHat()
    {
        if (m_to == m_from)
            return PosVector(0,0);

        PosVector res = m_to - m_from;
        double modThis = _hypot(res.x(), res.y());
        res = res / modThis;

        return res;
    }

    /* return point on *this with x coordinate == x */
    PosVector suchThatXequals(double x)
    {
        PosVector res(x, funcOfLine(x));

        return res;
    }

    /* return f(x) */
    double funcOfLine(double x)
    {
        double c = m_from.y() - gradient()*m_from.x();
        double res = gradient() * x + c;

        return res;
    }

    /* 
    return angle initialLine m_from m_to 
    
                      + m_to
                   ◿
                ◿
             ◿     theta
    m_from +-------------------- initial line
    */
    double angle()
    {
        PosVector pvLine = m_to - m_from;
        return pvLine.angle();
    }
};



#endif // have_Line

