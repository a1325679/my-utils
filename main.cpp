#include <iostream>
#include "common.h"
int main()
{
  std::string str = "aaa bbb ccc ddd eee fff";
  std::vector<std::string> a = split(str, ' ');
  for (auto &item : a)
  {
    std::cout << item << std::endl;
  }
}