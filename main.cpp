#include <iostream>
#include "common.h"
#include "file_operator.h"
#include "clock.h"
int main()
{
  std::cout<<CLOCK::getCurrentDateTimeString()<<std::endl;
}