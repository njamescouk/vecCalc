// Circle.h
#ifndef have_Circle
#define have_Circle

#include "PosVector.h"
#include "Line.h"
#include <cassert>
#include <cstdlib>
#include <cmath>

/* radians */
class Angle
{
    double m_value;

public:
    Angle (){}

    Angle (double d)
        : m_value(d)
    {}

    ~Angle(){}

    bool operator<(Angle rhs)
    {
        return m_value < rhs.m_value;
    }

    double operator-(Angle rhs)
    {
        return m_value - rhs.m_value;
    }

    double getValue()
    {
        return m_value;
    }

    int quadrant()
    {
        double modVal = fmod(m_value, 2*PI);
        if (modVal < 0)
            modVal += 2*PI;

        if (modVal <= PI/2)
            return 1;

        if (modVal <= PI)
            return 2;

        if (modVal < 3*PI/2)
            return 3;

        return 4;
    }

    /*
    int getAngle()
    {
        return m_value % 360;
    }
    */
};

class Circle
{
    PosVector m_centre;
    double m_radius;
    Angle m_arcStart;
    Angle m_arcEnd;
    bool m_isArc;

public:
    Circle(){}
    
    Circle(PosVector pv1, PosVector pv2, PosVector pv3)
        :m_isArc(false)
    {
        // compute circumcentre
        PosVector pvBis1 = pv1.bisect(pv2);
        PosVector pvBis2 = pv1.bisect(pv3);

        Line line1(pv1, pv2); 
        Line line2(pv1, pv3);

        if (fabs(line1.gradient() - line2.gradient()) < 1e-9)
        {
            fprintf (stderr 
                     ,"Circle: points %s, %s and %s are collinear\n"
                     , pv1.toString().c_str()
                     , pv2.toString().c_str()
                     , pv3.toString().c_str()
                     );
            exit (100);
        }

        Line lBis1 = line1.perpendicular(pvBis1);
        Line lBis2 = line2.perpendicular(pvBis2);

        m_centre = lBis1.intersect(lBis2);
        m_radius = m_centre.distance(pv1);

        double dist1 = m_centre.distance(pv1);
        double dist2 = m_centre.distance(pv2);
        double dist3 = m_centre.distance(pv3);
        assert(fabs(dist1 - dist2) < 1e-9 && fabs(dist2 - dist3) < 1e-9);
    }

    Circle(PosVector centre, double radius)
        :m_isArc(false)
        ,m_centre(centre)
        ,m_radius(radius)
    {
    }

    Circle(PosVector centre, PosVector pv)
        :m_isArc(false)
        ,m_centre(centre)
        ,m_radius(m_centre.distance(pv))
    {
    }

    Circle(double d, PosVector pv1, PosVector pv2, PosVector pv3)
        :m_isArc(true)
        ,m_centre(pv1)
        ,m_radius(d)
    {
        Angle a1 = (pv2 - pv1).angle();
        Angle a2 = (pv3 - pv1).angle();
        m_arcStart = a1;
        m_arcEnd = a2;
    }

    Circle(double d, PosVector pv1, double startAng, double endAng)
        :m_isArc(true)
        ,m_centre(pv1)
        ,m_radius(d)
        ,m_arcStart(startAng)
        ,m_arcEnd(endAng)
    {
    }

    virtual ~Circle(){}

    bool isArc()
    {
        return m_isArc;
    }

    /* angle in positive sense */
    double positiveDelta()
    {
        double res = m_arcEnd - m_arcStart;

        if (res < 0)
            res += 2*PI;

        return res;
    }

    void setIsArc(bool b)
    {
        m_isArc = true;
    }

    PosVector getCentre()
    {
        return m_centre;
    }

    void setCentre(PosVector pv)
    {
        m_centre = pv;
    }

    double getRadius()
    {
        return m_radius;
    }

    void getMaxMin(double &minWidth, double &minHeight, double &maxWidth, double &maxHeight)
    {
        //if (m_isArc)
        {
            PosVector N(m_centre.x(),            m_centre.y() + m_radius);
            PosVector E(m_centre.x() + m_radius, m_centre.y());
            PosVector S(m_centre.x(),            m_centre.y() - m_radius);
            PosVector W(m_centre.x() - m_radius, m_centre.y());
        
            N.getMaxMin(minWidth, minHeight, maxWidth, maxHeight);
            E.getMaxMin(minWidth, minHeight, maxWidth, maxHeight);
            S.getMaxMin(minWidth, minHeight, maxWidth, maxHeight);
            W.getMaxMin(minWidth, minHeight, maxWidth, maxHeight);
        }
        //else
        {
            ;
        }
    }

    PosVector arcStart()
    {
        /* int quadrant = m_arcStart.quadrant(); */
        double deltaX = m_radius*cos(m_arcStart.getValue());
        double deltaY = m_radius*sin(m_arcStart.getValue());

        PosVector res(m_centre.x() + deltaX, m_centre.y() + deltaY);

        return res;
    }

    PosVector arcEnd()
    {
        /* int quadrant = m_arcEnd.quadrant(); */
        double deltaX = m_radius*cos(m_arcEnd.getValue());
        double deltaY = m_radius*sin(m_arcEnd.getValue());

        PosVector res(m_centre.x() + deltaX, m_centre.y() + deltaY);

        return res;
    }

    std::string toString()
    {
        std::string res;
        char buf[BUFSIZ];
        sprintf(buf, 
                "radius: %.2f, centre: ", 
                m_radius);
        res += buf;
        res += m_centre.toString();

        return res;
    }
};


#endif // have_Circle

