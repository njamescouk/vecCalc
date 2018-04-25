// AngleTable.h
#ifndef have_AngleTable
#define have_AngleTable

#include <map>
#include <string>
#include "PosVector.h"

struct PointTriple
{
    PosVector point1;
    PosVector point2;
    PosVector point3;

    PointTriple(){}

    PointTriple(PosVector p1, PosVector p2, PosVector p3)
        :point1(p1)
        ,point2(p2)
        ,point3(p3)
    {}

    virtual ~PointTriple(){}

    std::string toString()
    {
        return point1.toString() + " " + point2.toString() + " " + point3.toString();
    }
};

class AngleTable : public std::map<std::string, PointTriple>
{
public:
    AngleTable(){}
    virtual ~AngleTable(){}
    
    void dump(FILE *fp)
    {
        fprintf(fp, "angles:\n");
        iterator it;
        for (it = begin(); it != end(); it++)
        {
            fprintf(fp, "  %s %s\n", it->first.c_str(), it->second.toString().c_str());
        }
    }
};



#endif // have_AngleTable

