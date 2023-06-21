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

#ifndef __FILE_OPERATOR_H__
#define __FILE_OPERATOR_H__
#include <fstream>
#include <string>
// eof()： 表示如果读文件到达文件末尾，返回true
// bad()：如果在读过程中出错，返回 true
// fail()：读写过程出错或格式错误时返回true
class MyFile
{
public:
  MyFile(std::string file_name = "", std::ios_base::openmode mode = std::ios::in | std::ios::out);
  MyFile(const MyFile &file) = delete;
  MyFile(const MyFile &&file) = delete;
  MyFile &operator=(const MyFile &file) = delete;
  virtual ~MyFile();
  int OpenFile(std::string file_name, std::ios_base::openmode mode = std::ios::in | std::ios::out);
  int ReadAChr(char &chr);         // 读一个字符
  int ReadALine(std::string &str); // 读一行字符
  int WriteAChr(char c);
  int WriteALine(std::string str);

  std::string ReadAWord(std::string split_str);
  char ReadAChr();
  std::string ReadALine();

private:
  std::fstream io_;
  std::string file_name_;
};

#endif

#ifndef __CLOCK_H__
#define __CLOCK_H__
#include <string>
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