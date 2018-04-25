// CircleDefinition.h
#ifndef have_CircleDefinition
#define have_CircleDefinition

#include <string>
#include <cstdlib>
#include "Name.h"

enum CIRCLEDEFINITION_TYPE
{
    CIRCLEDEFINITION_NONE,
    CIRCLEDEFINITION_CIRCUMCIRCLE,
    CIRCLEDEFINITION_CENTRE_RADIUS,
    CIRCLEDEFINITION_CENTRE_POINT,
    CIRCLEDEFINITION_ARC_CENTRE_PT_PT,
    CIRCLEDEFINITION_ARC_CENTRE_ANG_ANG,
};

class CircleDefinition
{
    CIRCLEDEFINITION_TYPE m_type;
    Name m_name;
    std::string m_ref1;
    std::string m_ref2;
    std::string m_ref3;
    double m_radius;
    double m_startAng;
    double m_endAng;

public:
    CircleDefinition()
        :m_type(CIRCLEDEFINITION_NONE)
    {}

    CircleDefinition(std::string name, std::string ref1, std::string ref2, std::string ref3)
        :m_type(CIRCLEDEFINITION_CIRCUMCIRCLE)
        ,m_name(name)
        ,m_ref1(ref1)
        ,m_ref2(ref2)
        ,m_ref3(ref3)
    {}

    CircleDefinition(std::string name, std::string ref1, double d)
        :m_type(CIRCLEDEFINITION_CENTRE_RADIUS)
        ,m_name(name)
        ,m_ref1(ref1)
        ,m_radius(d)
    {}

    CircleDefinition(std::string name, std::string ref1, std::string ref2)
        :m_type(CIRCLEDEFINITION_CENTRE_POINT)
        ,m_name(name)
        ,m_ref1(ref1)
        ,m_ref2(ref2)
    {}

    CircleDefinition(std::string name
                     , double d
                     , std::string ref1
                     , std::string ref2
                     , std::string ref3)
        :m_type(CIRCLEDEFINITION_ARC_CENTRE_PT_PT) 
        ,m_radius(d)
        ,m_name(name)
        ,m_ref1(ref1)
        ,m_ref2(ref2)
        ,m_ref3(ref3)
    {
    }

    CircleDefinition(std::string name
                     , double d
                     , std::string ref1
                     , double startAng
                     , double endAng)
        :m_type(CIRCLEDEFINITION_ARC_CENTRE_ANG_ANG) 
        ,m_radius(d)
        ,m_name(name)
        ,m_startAng(startAng)
        ,m_endAng(endAng)
    {
    }

    virtual ~CircleDefinition(){}

    std::string getName()
    {
        return m_name;
    }

};



#endif // have_CircleDefinition

