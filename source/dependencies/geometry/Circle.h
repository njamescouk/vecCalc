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

    bool operator<=(Angle rhs)
    {
        return m_value <= rhs.m_value;
    }

    bool operator>(Angle rhs)
    {
        return m_value > rhs.m_value;
    }

    bool operator>=(Angle rhs)
    {
        return m_value >= rhs.m_value;
    }

    double operator-(Angle rhs)
    {
        return m_value - rhs.m_value;
    }

    double radians()
    {
        return m_value;
    }

    double degrees()
    {
        return m_value*360/(2*PI);
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
};

/*
    arc is specified from start to end with angle 
    increasing anti clockwise from x = 0

    start = 350 deg, end = 310 deg means start at 
    350 deg and keep going till you hit 310 deg
*/
class Circle
{
    PosVector m_centre;
    double m_radius;
    Angle m_arcStart;
    Angle m_arcEnd;
    bool m_isArc;

    bool arcCrossesZero()
    {
        return m_arcStart > m_arcEnd;
    }

    bool inArc(PosVector pv)
    {
        Angle a = (pv - m_centre).angle();

        if (arcCrossesZero())
        {
            return !((a < m_arcStart) && (a > m_arcEnd));
        }
        else
        {
            return (a >= m_arcStart) && (a <= m_arcEnd);
        }

        return true;
    }

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

    Circle(PosVector pv1, double d, PosVector pv2, PosVector pv3)
        :m_isArc(true)
        ,m_centre(pv1)
        ,m_radius(d)
    {
        Angle a1 = (pv2 - pv1).angle();
        Angle a2 = (pv3 - pv1).angle();
        m_arcStart = a1;
        m_arcEnd = a2;
    }

    Circle(PosVector pv1, double d, double startAng, double endAng)
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

    double getArcStart()
    {
        return m_arcStart.radians();
    }

    double getArcEnd()
    {
        return m_arcEnd.radians();
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
        double deltaX = m_radius*cos(m_arcStart.radians());
        double deltaY = m_radius*sin(m_arcStart.radians());

        PosVector res(m_centre.x() + deltaX, m_centre.y() + deltaY);

        return res;
    }

    PosVector arcEnd()
    {
        /* int quadrant = m_arcEnd.quadrant(); */
        double deltaX = m_radius*cos(m_arcEnd.radians());
        double deltaY = m_radius*sin(m_arcEnd.radians());

        PosVector res(m_centre.x() + deltaX, m_centre.y() + deltaY);

        return res;
    }

    bool intersect(Circle circ, PosVector &pv)
    {
        if(m_centre.x() > circ.getCentre().x())
            return circ.intersect(*this, pv);

        bool res = false;

        double centreDistance = m_centre.distance(circ.getCentre());
        bool tooFar = (centreDistance > (m_radius + circ.getRadius()));
        bool tooNear = (centreDistance < fabs(m_radius - circ.getRadius()));
        bool justRight = !tooFar && !tooNear;
        bool areArcs = m_isArc && circ.isArc();
        bool isRunner = areArcs && justRight;

        /* see page 1 of intersectCircle.pdf */
        if (isRunner)
        {
            double r1 = m_radius;
            double r2 = circ.getRadius();
            double r1Sq = m_radius*m_radius;
            double r2Sq = circ.getRadius()*circ.getRadius();
            double baseSq = centreDistance*centreDistance;

            double cosC1 = (r1Sq + baseSq - r2Sq)/(2*r1*centreDistance);
            Angle A(acos(cosC1));
            double deltaX = r1 * cosC1;
            double deltaY = r1 * sqrt(1 - cosC1*cosC1);
            Angle a = (circ.getCentre() - m_centre).angle();
            double ad = a.degrees();
            PosVector delta(deltaX, deltaY);
            PosVector deltaRot = delta.rotate(a.radians());
            PosVector p1 = m_centre + deltaRot;

            PosVector delta1(deltaX, -deltaY);
            PosVector delta1Rot = delta1.rotate(a.radians());
            PosVector p2 = m_centre + delta1Rot;
            
            /* 
                p1 or p2 have to be present in one or other of the arcs, but not both

                p1 in both arcs | p2 in both arcs | no show | !p1InBoth && !p2InBoth | p1InBoth && p2InBoth 
                        F                F            T                 T                        F
                        T                F            F                 F                        F
                        F                T            F                 F                        F
                        T                T            T                 F                        T
            */
            bool p1InArc = inArc(p1);
            bool p2InArc = inArc(p2);

            bool p1InOtherArc = circ.inArc(p1);
            bool p2InOtherArc = circ.inArc(p2);
            
            bool p1InBoth = p1InArc && p1InOtherArc;
            bool p2InBoth = p2InArc && p2InOtherArc;

            bool noShow = (!p1InBoth && !p2InBoth) || (p1InBoth && p2InBoth);

            bool pEverywhere = p1InArc && p2InArc && p1InOtherArc && p2InOtherArc;
            bool noP = !p1InArc && !p2InArc && !p1InOtherArc && !p2InOtherArc;

            if (noShow)
            {
                //if (noP)
                    fprintf(stderr, "Circle::intersect - nothing found\n");
                //else
                //    fprintf(stderr, "Circle::intersect - ambiguous spec.\n");

                res = false;
            }
            else
            {
                if (p1InBoth)
                    pv = p1;
                else if (p2InBoth)
                    pv = p2;

                res = true;
            }
        }

        return res;
    }

    bool postiveFuncOf(double x, double &y)
    {
        if (fabs(x - m_centre.x()) > m_radius)
            return false;

        double rSq = m_radius * m_radius;
        double xMinusCSq = (x - m_centre.x()) * (x - m_centre.x());
        y = m_centre.y() + sqrt(rSq - xMinusCSq); 

        return true;
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
        if (m_isArc)
        {
            sprintf(buf, ", arc (%.2f, %.2f)", m_arcStart.degrees(), m_arcEnd.degrees());
            res += buf;
        }

        return res;
    }
};


#endif // have_Circle

/*
// arcInter.veccalc

pt O 0 0

pt delta 360 257
pt delta1 360 -257
pt deltaRot 400 -190
pt delta1Rot -50 -440
#svg colY
circ d O delta
circ d1 O delta1
pt p1 500 60
pt p2 50 -190

#svg colK
pt A 100 250
pt C 200 70
#svg nodraw
pt B 500 60
#svg draw

line AB A B
line AC A C
line BC B C

circ c1 A B
circ c2 C B

#svg colC
arc a1 A B 300 70
#svg colR
arc a2 C B 310 10
pt X inter a2 a1
*/