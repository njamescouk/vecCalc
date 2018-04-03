set COMPILE_CPP_SRCS=Definition.cpp DefinitionList.cpp LineDefinition.cpp PointDefinition.cpp dependencies\parseCmdline\source\lex.pcl.c dependencies\parseCmdline\source\pcl.tab.c dependencies\split_string\split_string.cpp dependencies\stringtime\stringtime.cpp lex.yy.c main.cpp vecCalcGlobals.cpp y.tab.c
set COMPILE_INCLUDES=-Idependencies\geometry -Idependencies\yacc -Idependencies\parseCmdline\source -Idependencies\split_string -Idependencies\stringtime
set COMPILE_DEFINES=-DSQLITE_CORE -DSQLITE_ENABLE_MD5
g++ -o vecCalc.exe %COMPILE_INCLUDES% %COMPILE_DEFINES% -x c++ %COMPILE_CPP_SRCS% 
