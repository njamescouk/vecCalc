// PosVector.h
#ifndef have_PosVector
#define have_PosVector

#pragma warning( disable : 4996 )
#include <cmath>
#include <cfloat>
#include <string>
#include <cstdio>

#define PI       3.14159265358979323846

class PosVector
{
    double m_x;
    double m_y;
public:
    PosVector()
        : m_x(0)
        , m_y(0)
    {}

    PosVector(double x, double y)
        : m_x(x)
        , m_y(y)
    {}

    virtual ~PosVector() {}

    /* bigger y wins, bigger x wins the tie */
    bool operator< (const PosVector &rhs) const
    {
        if (m_y < rhs.m_y)
            return true;
        else if (fabs(m_y - rhs.m_y) < DBL_EPSILON)
            /* effectively m_y == rhs.m_y */
            return m_x < rhs.m_x;

        return false;
    }

    double x()
    {
        return m_x;
    }

    double y()
    {
        return m_y;
    }

    bool operator==(PosVector p)
    {
        return m_x == p.m_x && m_y == p.m_y;
    }

    bool operator!=(PosVector p)
    {
        return !(*this == p);
    }

    /* scalar product */
    double operator* (PosVector p)
    {
        return (m_x * p.m_x + m_y * p.m_y);
    }

    PosVector operator* (double d)
    {
        return PosVector(d*m_x, d*m_y);
    }

    PosVector operator/ (double d)
    {
        return PosVector(m_x/d, m_y/d);
    }

    PosVector operator+ (PosVector p)
    {
        return PosVector(p.x() + m_x, p.y() + m_y);
    }

    PosVector operator- (PosVector p)
    {
        return PosVector(m_x - p.x(), m_y - p.y());
    }

    double mod()
    {
        return _hypot(m_x, m_y);
    }

    PosVector translate(double x, double y)
    {
        PosVector res(m_x + x, m_y + y);

        return res;
    }

    double distance(PosVector p)
    {
        double deltaX = m_x - p.x();
        double deltaY = m_y - p.y();

        return _hypot(deltaX, deltaY);
    }

    /* 
        return angle to initialLine 

                      + (m_x, m_y)
                   ◿
                ◿
             ◿     theta
         O +-------------------- initial line
    */
    double angle()
    {
        double res = 0;

        int quad = quadrantOf();

        double xHat = m_x/mod();
        double yHat = m_y/mod();

        switch(quad)
        {
            case 1:
                res = asin(yHat);
                break;
            case 2:
                res = acos(xHat);
                break;
            case 3:
                res = 2*PI - acos(xHat);
                break;
            case 4:
                res = 2*PI + asin(yHat);
                break;
        }

        return res;
    }

    /* return PosVector of a place half way towards p */
    PosVector bisect(PosVector p)
    {
        PosVector halfPos = (*this - p);
        halfPos = halfPos*.5;
        PosVector res(p + halfPos);

        return res;
    }

    /* return *this rotated by a radians */
    PosVector rotate(double a)
    {
        double xR = m_x*cos(a) - m_y*sin(a),
               yR = m_x*sin(a) + m_y*cos(a);
        PosVector res(xR, yR);

        return res;
    }

    std::string toPath()
    {
        // svg y is south not north
        char buf[BUFSIZ];
        if (fabs(m_x) < 1e6 && fabs(m_y) < 1e6) 
            sprintf(buf, "%.2f %.2f", m_x, -m_y);
        else
            sprintf(buf, "%.2g %.2g", m_x, -m_y);

        return std::string(buf);
    }

    std::string toString()
    {
        char buf[BUFSIZ];
        if (fabs(m_x) < 1e6 && fabs(m_y) < 1e6) 
            sprintf(buf, "(%.2f,%.2f)", m_x, m_y);
        else
            sprintf(buf, "(%.2e,%.2e)", m_x, m_y);

        return std::string(buf);
    }

    std::string toReversePath()
    {
        char buf[BUFSIZ];
        
        // svg y is south not north
        if (fabs(m_x) < 1e6 && fabs(m_y) < 1e6) 
            sprintf(buf, "(%.2f,%.2f)", -m_y, m_x);
        else
            sprintf(buf, "(%.2e,%.2e)", -m_y, m_x);

        return std::string(buf);
    }

    void getMaxMin(double &minX, double &minY, double &maxX, double &maxY)
    {
        if (m_x > maxX)
            maxX = m_x;
        if (m_y > maxY)
            maxY = m_y;
        if (m_x < minX)
            minX = m_x;
        if (m_y < minY)
            minY = m_y;
    }

    int quadrantOf()
    {
        if (m_y >= 0 && m_x >= 0)
            return 1;

        if (m_y >= 0 && m_x < 0)
            return 2;

        if (m_y < 0 && m_x < 0)
            return 3;

        if (m_y < 0 && m_x >= 0)
            return 4;

        return 42;
    }
};



#endif // have_PosVector

