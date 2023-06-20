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
  int ReadAChr(char & chr); //读一个字符
  int ReadALine(std::string& str); //读一行字符
  int WriteAChr(char c);
  int WriteALine(std::string str);

  char ReadAChr();
  std::string ReadALine();
private:
  std::fstream io_;
  std::string file_name_;
};

#endif