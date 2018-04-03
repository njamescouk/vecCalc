// Name.h
#ifndef have_Name
#define have_Name

#include <string>

class Name : public std::string
{

public:
    Name(){}

    Name(const char *s)
        : std::string(s)
    {}

    Name(std::string s)
        : std::string(s)
    {}

    virtual ~Name(){}
};



#endif // have_Name
