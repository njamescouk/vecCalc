// CmdLineSpec.h
#ifndef have_CmdLineSpec
#define have_CmdLineSpec

#include <map>
#include <string>
#include <cstdio>
#include "OptionSpec.h"
#include "split_string.h"

class CmdLineSpec : public std::map<std::string, OptionSpec>
{
public:
    CmdLineSpec()
    {
    }

    CmdLineSpec(std::map<std::string, OptionSpec> specs)
    {
        insert(specs.begin(), specs.end());
    }

    virtual ~CmdLineSpec()
    {
    }

    bool hasFlag(char *flag)
    {
        if(find(flag) != end())
        {
            return true;
        }

        return false;
    }

    OptionSpec getSpec(std::string name)
    {
        std::map<std::string, OptionSpec>::iterator it = find(name);
        if(it != end())
        {
            return it->second;
        }

        return OptionSpec();
    }

    void help(std::string blurb, FILE* fp)
    {
        fprintf(fp, "usage: %s\noptions are:\n", blurb.c_str());
        std::map<std::string, OptionSpec>::iterator it;
        for (it = begin(); it != end(); it++)
        {
            std::string opt = it->first;
            OptionSpec osCur = it->second;
            std::string hText = osCur.getHelpText();
            splitstring::subst(hText, "\n", "\n                  ");
            if (!hText.empty())
                fprintf(fp, "    -%-10s : %s\n", opt.c_str(), hText.c_str());
        }
    }

};



#endif // have_CmdLineSpec

