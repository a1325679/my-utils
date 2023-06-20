#include <iostream>
#include "file_operator.h"
int main()
{
  char c;
  std::string s;
  MyFile a("../readfile", std::ios::in);
  a.ReadALine(s);
  std::cout<<s<<std::endl;
}