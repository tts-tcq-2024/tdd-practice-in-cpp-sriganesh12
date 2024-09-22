#include "StringCalculator.h"
#include <string>
#include <cctype>
#include <sstream>
#include <iostream>
#include <stdexcept>

void StringCalculator::checkForException(const std::string& item)
{
    for(char ch : item)
      if(isalpha(ch))
      {
          std::string message = "Alphabets not allowed: ";
          std::runtime_error(message)
      }
}

int StringCalculator::addNumbersOnly(const std::string& item)
{
  int value = std::stoi(item);
  if(value > 0 && value <= 1000)
  {
    return value;
  }
  return 0;
}

void StringCalculator::prepareString(const std::string& name)
{
  if(!name.empty())
  {
    if(name.substr(0,2) == "//")
    {
      char delimiter = name[2];
      name = name.substr(4);
      str::replace(name.begin(), name.end(), delimiter, ',');
    }
    str::replace(name.begin(), name.end(), '\n', ',');
  }
}

int StringCalculator::add(const std::string& name)
{
  prepareString(name);
  std::stringstream ss(name);
  std::string item;
  int sum = 0;

  while (std::getline(ss, item, ','))
  {
    checkForException(item);
    int value = addNumbersOnly(item);
    sum += value;
  }

  return sum;
}
