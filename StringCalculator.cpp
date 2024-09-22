#include "StringCalculator.h"

using namespace std;

void StringCalculator::checkForException(const string item)
{
    for(char ch : item)
      if(isalpha(ch))
      {
          string message = "Alphabets not allowed";
          throw runtime_error(message);
      }
}

void StringCalculator::checkForNegativeInteger(const string item)
{
  int value = stoi(item);
  if(value < 0)
  {
      string message = "Negative Integers not allowed";
      throw runtime_error(message);
  }
}

int StringCalculator::checkUpperLimitsForInteger(const string item)
{
  int value = stoi(item);
  if(value <= 1000)
  {
    return value;
  }
  return 0;
}

void StringCalculator::prepareString(string name)
{
  if(!name.empty())
  {
    if(name.substr(0,2) == "//")
    {
      char delimiter = name[2];
      name = name.substr(4);
      replace(name.begin(), name.end(), delimiter, ',');
    }
    replace(name.begin(), name.end(), '\n', ',');
  }
}

int StringCalculator::add(string name)
{
  prepareString(name);
  stringstream ss(name);
  string item;
  int sum = 0;

  while (getline(ss, item, ','))
  {
    checkForException(item);
    int value = addNumbersOnly(item);
    sum += value;
  }

  return sum;
}
