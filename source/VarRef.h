// VarRef.h
#ifndef have_VarRef
#define have_VarRef

class VarRef : public std::string
{
public:
    VarRef(){}

    VarRef(const char *s)
        : std::string(s)
    {}

    virtual ~VarRef(){}
};



#endif // have_VarRef

