#include "file_operator.h"

MyFile::MyFile(std::string file_name, std::ios_base::openmode mode) : file_name_(file_name)
{
  if (file_name_ != "")
  {
    io_.open(file_name_, mode);
    if (!io_.is_open() || io_.fail())
    {
      printf("文件打开失败 %s:%d\n", __func__, __LINE__);
      return;
    }
  }
}
int MyFile::ReadAChr(char &chr)
{
  if (!io_.is_open())
  {
    printf("文件并未打开 %s:%d\n", __func__, __LINE__);
    return -1;
  }
  chr = io_.get();
  // printf("%c\n", chr);
  if (io_.bad() | io_.fail())
  {
    printf("文件读取出现错误\n");
    return -1;
  }
  if (io_.eof())
  {
    printf("文件已读到结尾\n");
    return 0;
  }
  return 1;
}
int MyFile::ReadALine(std::string &str)
{
  if (!io_.is_open())
  {
    printf("文件并未打开 %s:%d\n", __func__, __LINE__);
    return -1;
  }
  getline(io_, str);
  if (io_.bad() | io_.fail())
  {
    printf("文件读取出现错误\n");
    return -1;
  }
  if (io_.eof())
  {
    printf("文件已读到结尾\n");
    return 0;
  }
  return 1;
}
char MyFile::ReadAChr()
{
  char c;
  int ret = ReadAChr(c);
  return c;
}
std::string MyFile::ReadALine()
{
  std::string str;
  int ret = ReadALine(str);
  return str;
}

int MyFile::WriteAChr(char c)
{
  if (!io_.is_open())
  {
    printf("文件并未打开 %s:%d\n", __func__, __LINE__);
    return -1;
  }
  io_.put(c);
  if (io_.bad() | io_.fail())
  {
    printf("文件读取出现错误\n");
    return -1;
  }
  return 1;
}
int MyFile::WriteALine(std::string str)
{
  if (!io_.is_open())
  {
    printf("文件并未打开 %s:%d\n", __func__, __LINE__);
    return -1;
  }
  io_ << str;
  if (str.back() != '\n')
    io_ << '\n';
  if (io_.bad() | io_.fail())
  {
    printf("文件读取出现错误\n");
    return -1;
  }
  return 1;
}
std::string MyFile::ReadAWord(std::string split_str)
{
  std::string str;
  if (!io_.is_open())
  {
    printf("文件并未打开 %s:%d\n", __func__, __LINE__);
    return str;
  }
  if (io_.eof())
  {
    printf("文件已读到结尾\n");
    return str;
  }
  getline(io_, str, ' '); // 读取一个单词，以空格作为分隔符
  if (io_.bad() | io_.fail())
  {
    printf("文件读取出现错误\n");
    return str;
  }
  return str;
}
int MyFile::OpenFile(std::string file_name, std::ios_base::openmode mode)
{
  if (io_.is_open())
  {
    io_.close();
  }
  io_.open(file_name, mode);
  if (!io_.is_open() || io_.fail())
  {
    printf("文件打开失败 %s:%d\n", __func__, __LINE__);
    return -1;
  }
  return 0;
}
MyFile::~MyFile()
{
  if (io_.is_open())
  {
    io_.close();
  }
}