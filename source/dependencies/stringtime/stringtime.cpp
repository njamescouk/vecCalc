#pragma warning( disable : 4786 )

#include "stringtime.h"
#include <vector>
#include "split_string.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#pragma warning (disable: 4996)

std::string timeSep = ":";
std::string dateSep = "-";

stringtime::stringtime()
{
    ;
}

stringtime::~stringtime()
{
    ;
}

// ts is dd/mm/yyyy hh:mm:ss.ss am|pm
time_t stringtime::convert(std::string ts)
{
    time_t res = 0;
    std::vector<std::string> fields;

    splitstring::split(ts, fields);
    if (fields.size() == 3)
    {
        bool isPM = (strcmp(fields[2].c_str(), "pm") == 0);
        std::vector<std::string> datefields;
        std::vector<std::string> timefields;
        std::string dateSep = "/";
        if (ts.find("-") != std::string::npos)
            dateSep = "-";
        splitstring::split(fields[0], datefields, dateSep);
        splitstring::split(fields[1], timefields, ":");
        if(datefields.size() == 3 && timefields.size() == 3)
        {
            struct tm tms;
            tms.tm_hour = atoi(timefields[0].c_str());
            if (isPM)
                tms.tm_hour += 12;
            tms.tm_min = atoi(timefields[1].c_str());
            tms.tm_sec = (int)(floor(atof(timefields[2].c_str()) + .5));

            tms.tm_mday = atoi(datefields[0].c_str());
            tms.tm_mon = atoi(datefields[1].c_str()) - 1; // months are 0 based
            tms.tm_year = atoi(datefields[2].c_str()) - 1900;

            res = mktime(&tms);
        }
    }

    return res;
}

// ds is yyyy-mm-dd
// ts is hh:mm:ss.ss
time_t stringtime::convertdt(std::string ds, std::string ts)
{
    time_t res = 0;
    struct tm tms;
    bool bValid = true;

    std::vector<std::string> fields;

    std::vector<std::string> datefields;
    splitstring::split(ds, datefields, dateSep);
    if(datefields.size() == 3)
    {
        tms.tm_year = atoi(datefields[0].c_str()) - 1900;
        tms.tm_mon = atoi(datefields[1].c_str()) - 1; // months are 0 based
        tms.tm_mday = atoi(datefields[2].c_str());
    }
    else
    {
        bValid = false;
    }

    fields.resize(0);

    std::vector<std::string> timefields;
    splitstring::split(ts, timefields, timeSep);
    if(timefields.size() == 3)
    {
        tms.tm_hour = atoi(timefields[0].c_str());
        tms.tm_min = atoi(timefields[1].c_str());
        tms.tm_sec = (int)(floor(atof(timefields[2].c_str()) + .5));
    }
    else
    {
        bValid = false;
    }

    if (bValid)
        res = mktime(&tms);
    else
        res = (time_t) -1;

    return res;
}

std::string stringtime::write(time_t t)
{
    char buf[BUFSIZ];

    strftime(buf, BUFSIZ-1, "%Y-%m-%d %H:%M:%S", gmtime(&t));

    std::string res = buf;

    return res;
}

std::string stringtime::pukkaTimeStamp()
{
    char buf[BUFSIZ];

    time_t t = time(NULL);
    strftime(buf, BUFSIZ-1, "%Y-%m-%dT%H:%M:%SZ", gmtime(&t));

    std::string res = buf;

    return res;
}

std::string stringtime::writeDate(int year, int month, int day)
{
    char buf[BUFSIZ];

    sprintf(buf, "%d-%0.2d-%0.2d", year, month, day);

    std::string res = buf;

    return res;
}

std::string stringtime::writeVDate(int year, int month, int day)
{
    char buf[BUFSIZ];

    sprintf(buf, "%d%0.2d%0.2d", year, month, day);

    std::string res = buf;

    return res;
}

// longDate is YYYY-MM-DD
bool stringtime::split (std::string longDate, 
                        std::string &y, 
                        std::string &m, 
                        std::string &d)
{
    std::vector<std::string> fields;
    splitstring::split(longDate, fields, dateSep);
    if (fields.size() >= 3)
    {
        y = fields[0];
        m = fields[1];
        d = fields[2];
    }
    else
    {
        return false;
    }

    return true;
}

// longDate is YYYY-MM-DD
bool stringtime::split (std::string longDate, 
                        int &d, 
                        int &m, 
                        int &y)
{
    std::vector<std::string> fields;
    splitstring::split(longDate, fields, dateSep);
    if (fields.size() >= 3)
    {
        y = atoi(fields[0].c_str());
        m = atoi(fields[1].c_str());
        d = atoi(fields[2].c_str());
    }
    else
    {
        return false;
    }

    return true;
}

/*
bool stringtime::split(std::string longDateTime, 
                         int &year, 
                         int &month, 
                         int &day,
                         int &hour, 
                         int &min,
                         double &sec)
{
    return false;
}
*/

// longDateTime is YYYY-MM-DD [HH:MM:SS.SS]
bool stringtime::split(std::string longDateTime, 
                         std::string &year, 
                         std::string &month, 
                         std::string &day,
                         std::string &hour, 
                         std::string &min,
                         std::string &sec)
{
    std::vector<std::string> DT;
    splitstring::split(longDateTime, DT);

    if (DT.size() > 0)
    {
        if (!split(DT[0], year, month, day))
            return false;
    }

    if (DT.size() == 2)
    {
        std::vector<std::string> HMS;
        splitstring::split(DT[1], HMS, timeSep);

        if (HMS.size() > 0)
            hour = HMS[0];

        if (HMS.size() > 1)
            min = HMS[1];

        if (HMS.size() > 2)
            sec = HMS[2];

        if (HMS.size() > 3)
            return false;
    }

    return true;
}

/* time is HH:MM[:SS.ssss] */
bool stringtime::split(std::string time, int &h, int &m, double &s)
{
    std::vector<std::string> T;
    splitstring::split(time, T, timeSep);

    if (!(T.size() == 2 || T.size() == 3))
    {
        return false;
    }

    h = atoi(T[0].c_str());
    m = atoi(T[1].c_str());
    if (T.size() == 3)
        s = atof(T[2].c_str());
    else
        s = 0.0;

    return true;
}

// d is YYYY-MM-DD, returns DD-MM-YYYY; or vice versa
std::string stringtime::reverseShort (std::string src) 
{
    std::string one; 
    std::string two; 
    std::string three;

    split(src, one, two, three);

    std::string res;
    res = three + dateSep + two + dateSep + one;

    return res;
}

std::string stringtime::suffix (int n)
{
    if (n <= 0)
        return "";

    switch(n)
    {
    case 11:
    case 12:
    case 13:
        return "th";
    }

    switch(n%10)
    {
    case 1:
        return "st";
    case 2:
        return "nd";
    case 3:
        return "rd";
    }

    return "th";
}

bool stringtime::getDate(std::string datetime, std::string &date)
{
    std::vector<std::string> fields;
    splitstring::split(datetime, fields);
    if (fields.size() == 2)
    {
        date = fields[0];
        return true;
    }

    return false;
}
