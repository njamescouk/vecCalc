// VarDefinition.h
#ifndef have_VarDefinition
#define have_VarDefinition

#include "Name.h"
#include <string>

class VarDefinition
{
    double m_value;
    Name m_name;

public:
    VarDefinition()
        : m_value(0.0)
    {}

    VarDefinition(std::string s, double d)
        :m_name(s) 
        ,m_value(d)
    {}

    virtual ~VarDefinition(){}

    std::string getName()
    {
        return m_name;
    }
};



#endif // have_VarDefinition
