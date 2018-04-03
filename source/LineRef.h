// LineRef.h
#ifndef have_LineRef
#define have_LineRef

#include <string>

class LineRef : public std::string
{

public:
    LineRef(){}

    LineRef(const char *s)
        : std::string(s)
    {}

    virtual ~LineRef(){}
};



#endif // have_LineRef
