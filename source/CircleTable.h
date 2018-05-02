// CircleTable.h
#ifndef have_CircleTable
#define have_CircleTable

#include <map>
#include <string>
#include "Circle.h"

class CircleTable : public std::map<std::string, Circle>
{
public:
    CircleTable(){}
    virtual ~CircleTable(){}

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
        fprintf(fp, "circles:\n");
        iterator it;
        for (it = begin(); it != end(); it++)
        {
            fprintf(fp, "  %s %s\n", it->first.c_str(), it->second.toString().c_str());
        }
    }
};



#endif // have_CircleTable

