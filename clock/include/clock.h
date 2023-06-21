#ifndef __CLOCK_H__
#define __CLOCK_H__
#include<string>
class CLOCK
{
public:
  static int SleepMillSecond(unsigned int time);
  static int SleepSecond(unsigned int time);
  static int SleepMicroSecond(unsigned int time);
  static std::string getCurrentDateTimeString();
  
private:
};

#endif