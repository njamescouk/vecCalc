// PointTable.h
#ifndef have_PointTable
#define have_PointTable

#include <map>
#include <string>
#include "PosVector.h"

/* map pointName -> PosVector */
class PointTable : public std::map<std::string, PosVector>
{
public:
    PointTable(){}
    virtual ~PointTable(){}

    void getMaxMin(double &minX, double &minY, double &maxX, double &maxY)
    {
        iterator it;
        for (it = begin(); it != end(); it++)
        {
            it->second.getMaxMin(minX, minY, maxX, maxY);
        }
    }
    
    void dump(FILE *fp)
    {
        fprintf(fp, "points:\n");
        iterator it;
        for (it = begin(); it != end(); it++)
        {
            fprintf(fp, "  %s %s\n", it->first.c_str(), it->second.toString().c_str());
        }
    }
};



#endif // have_PointTable

