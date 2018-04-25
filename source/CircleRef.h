// CircleRef.h
#ifndef have_CircleRef
#define have_CircleRef

#include <string>

class CircleRef : public std::string
{
public:
    CircleRef(){}

    CircleRef(const char *s)
        : std::string(s)
    {}

    virtual ~CircleRef(){}
};



#endif // have_CircleRef

