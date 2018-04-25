// AngleDefinition.h
#ifndef have_AngleDefinition
#define have_AngleDefinition

#include "PointRef.h"
#include "Name.h"
#include <cstdio>


class AngleDefinition
{
    Name m_name;
    PointRef m_pointRef1;
    PointRef m_pointRef2;
    PointRef m_pointRef3;

public:
    AngleDefinition(){}

    AngleDefinition(Name n, PointRef p1, PointRef p2, PointRef p3)
        :m_name(n)
        ,m_pointRef1(p1)
        ,m_pointRef2(p2)
        ,m_pointRef3(p3)
    {}

    virtual ~AngleDefinition(){}

    std::string getName()
    {
        return m_name;
    }
};



#endif // have_AngleDefinition

