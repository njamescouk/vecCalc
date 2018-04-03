#ifndef have_timestring
#define have_timestring

#include <string>
#include <time.h>

class stringtime
{
public:
    stringtime();
    ~stringtime();
    static time_t convert(std::string ts);
    static time_t convertdt(std::string ds, std::string ts);
    static std::string write(time_t t);
    static std::string pukkaTimeStamp();
    static std::string writeDate(int year, int month, int day);
    static std::string writeVDate(int year, int month, int day);
    static bool split (std::string longDate, 
                       std::string &y, 
                       std::string &m, 
                       std::string &d);
    static bool split (std::string longDate, 
                        int &d, 
                        int &m, 
                        int &y);
    static bool split(std::string longDateTime, 
                         int &year, 
                         int &month, 
                         int &day,
                         int &hour, 
                         int &min,
                         double &sec);
    static bool split(std::string longDateTime, 
                      std::string &year, 
                      std::string &month, 
                      std::string &day,
                      std::string &hour, 
                      std::string &min,
                      std::string &sec);
    static bool split(std::string time, int &h, int &m, double &s);
    static std::string reverseShort (std::string src);
    static std::string suffix (int n);
    static bool getDate(std::string datetime, std::string &date);
};



#endif // have_timestring
