// DefinitionList.h
#ifndef have_DefinitionList
#define have_DefinitionList

#include <vector>
#include <cstdlib>
#include "Definition.h"

class DefinitionList : public std::vector<Definition>
{

public:
    DefinitionList(){}
    virtual ~DefinitionList(){}
};



#endif // have_DefinitionList
