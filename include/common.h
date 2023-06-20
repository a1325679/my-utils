#ifndef __COMMON_H__
#define __COMMON_H__
#include <string>
#include <sstream>
#include <vector>
// 工具函数
template <typename Out>
void split_internal(const std::string &s, char delim, Out result)
{
  std::stringstream ss;
  ss.str(s);
  std::string item;
  while (std::getline(ss, item, delim))
  {
    *(result++) = item;
  }
}
// 分割字符串
std::vector<std::string> split(const std::string &s, char &&delim);
#endif