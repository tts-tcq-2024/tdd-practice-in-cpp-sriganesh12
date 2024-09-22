#include "StringCalculator.h"
include <string>
#include <cctype>
#include <sstream>
#include <iostream>

int add(const std::string& name)
{
  if(name.empty())
  {
    return 0;
  }
  if(name.substr(0,2) == "//")
  {
    char delimiter = name[2];
    name = name.substr(4);
    str::replace(name.begin(), name.end(), delimiter, ',');
  }
  str::replace(name.begin(), name.end(), '\n', ',');

  std::stringstream ss(name);
  std::string item;
  int sum = 0;

  while (std::getline(ss, item, ','))
  {
    int value += std::stoi(item);
    if (value>0 && value<=1000)
    {
    sum += value;
    }
  }

  return sum;
}
