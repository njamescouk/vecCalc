#include <stdio.h>
#include <string.h>
#include "CmdLineParser.h" 
#include "PosVector.h"
#include "yaccFns.h" 
#include "vecCalcGlobals.h" 
#include "Line.h"
#include "DefinitionList.h"
#include "VecCalcSchedule.h"

#pragma warning( disable : 4996 )
 
void version(FILE *fp);

int main (int argc, char *argv[])
{
    progname = argv[0];
    CmdLineSpec specs;

    specs["h"] = OptionSpec(false, "this help");
    specs["v"] = OptionSpec(false, "version");
    specs["d"] = OptionSpec(false, "dump coordinates");
    specs["svg"] = OptionSpec(false, "(default)write svg paths and circles");
    specs["o"] = OptionSpec(true, "output filename");

    pcldebug = 0;
    CmdLineParser clp(argc, argv, specs);
    Cmdline cmdline = clp.parse();
    if (!cmdline.isValid())
    {
        return 1;
    }

    FILE *ifp = stdin;
    FILE *ofp = stdout;
 
    if (cmdline.hasOption("h"))
    {
        std::string blurb = progname;
        blurb += " options filename\nreads filename\n"
                 "or stdin and prints values of points\n"
                 "defined in the input\n";
        specs.help(blurb, stdout);
        return 0;
    }

    if (cmdline.hasOption("v"))
    {
        version(stdout);
        return 0;
    }

    bool writeSvg = true;

    if (cmdline.hasOption("svg"))
    {
        writeSvg = true;
    }

    if (cmdline.hasOption("d"))
    {
        writeSvg = false;
    }

    std::string inputFile = "stdin";
    if (cmdline.numArguments() > 0)
    {
        inputFile = cmdline.getArgument(0);
        ifp = fopen(inputFile.c_str(), "rt");
        if (ifp == 0)
        {
            perror (progname);
            return 1;
        }
    }
 
    bool ofpFailed = false;
    yyin = ifp;
    yydebug = 1;
    if (yyparse() == 0)
    {
        /* don't trash the output file if parsing fails */
        if (cmdline.hasOption("o"))
        {
            ofp = fopen(cmdline.getOptionValue("o").c_str(), "wt");
            if (ofp == 0)
            {
                perror (progname);
                ofpFailed = true;
            }
        }

        if (!ofpFailed)
            gSchedule.write(ofp, inputFile, writeSvg);
    }
    else
    {
        fprintf(stderr, "\n%s failed\n", progname);
    }

    if (ifp != stdin)
        fclose(ifp);
 
    if (!ofpFailed && ofp != stdout)
        fclose(ofp);
 
    return 0;
}


void version(FILE *fp)
{
    fprintf(fp, "%s version %s\n", progname, szVersion);
}
