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

int StringCalculator::getInteger(const string item)
{
    if(!item.empty())
    {
        return stoi(item);
    }
    return 0;
}

void StringCalculator::checkForNegativeInteger(const int value)
{
    if(value < 0)
    {
      string message = "Negative Integers not allowed";
      throw runtime_error(message);
    }
}

int StringCalculator::checkUpperLimitsForInteger(const int value)
{
  if(value <= 1000)
  {
    return value;
  }
  return 0;
}

void StringCalculator::prepareString(string& name)
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
    int value = getInteger(item);
    checkForNegativeInteger(value);
    int valueToAdd = checkUpperLimitsForInteger(value);
    sum += valueToAdd;
  }

  return sum;
}
