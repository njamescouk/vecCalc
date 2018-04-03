// PointRef.h
#ifndef have_PointRef
#define have_PointRef

#include <string>

class PointRef : public std::string
{

public:
    PointRef(){}

    PointRef(const char *s)
        : std::string(s)
    {}

    virtual ~PointRef(){}
};



#endif // have_PointRef
