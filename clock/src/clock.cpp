#include "clock.h"
#include <iostream>
#include <thread>
#include <sstream>
#include <iomanip>
int CLOCK::SleepMillSecond(unsigned int time)
{ // 1秒钟开始统计 CLOCKS_PER_SEC cpu每秒跳数
  auto beg = clock();
  for (int i = 0; i < time; i++)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    if ((clock() - beg) / (CLOCKS_PER_SEC / 1000) >= time)
    {
      break;
    }
  }
  // std::this_thread::sleep_for(std::chrono::milliseconds(time));
}
int CLOCK::SleepSecond(unsigned int time)
{
  std::this_thread::sleep_for(std::chrono::seconds(time));
}
int CLOCK::SleepMicroSecond(unsigned int time)
{
  std::this_thread::sleep_for(std::chrono::microseconds(time));
}

std::string CLOCK::getCurrentDateTimeString()
{
  auto now = std::chrono::system_clock::now();
  auto now_time_t = std::chrono::system_clock::to_time_t(now);
  auto now_tm = std::localtime(&now_time_t);

  std::ostringstream oss;
  oss << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S");
  return oss.str();
}
