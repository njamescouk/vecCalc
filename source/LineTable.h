// LineTable.h
#ifndef have_LineTable
#define have_LineTable


#include <map>
#include <string>
#include "Line.h"

/* map lineName -> Line */
class LineTable : public std::map<std::string, Line>
{
public:
    LineTable(){}
    virtual ~LineTable(){}

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
        fprintf(fp, "lines:\n");
        iterator it;
        for (it = begin(); it != end(); it++)
        {
            fprintf(fp, "  %s %s\n", it->first.c_str(), it->second.toString().c_str());
        }
    }
};



#endif // have_LineTable

