#include"util.h"
#ifndef DATE_H
#define DATE_H
#include<string>
class Date{
public:
static string dateString()
{
time_t now = time(0);
tm *ltm = localtime(&now);

return to_string(ltm->tm_year-118 + 2018) + "/" + to_string(ltm->tm_mon-2 +3) + "/" + to_string(ltm->tm_mday);
};
};
#endif
