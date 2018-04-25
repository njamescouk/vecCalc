// VarTable.h
#ifndef have_VarTable
#define have_VarTable

class VarTable : public std::map<std::string, double>
{
public:
    VarTable(){}
    virtual ~VarTable(){}
};



#endif // have_VarTable

