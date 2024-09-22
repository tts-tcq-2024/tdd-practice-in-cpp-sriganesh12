#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>

class StringCalculator
{
public:
int add(const std::string name);
private:
void prepareString(std::string name);
void checkForException(const std::string name);
int addNumbersOnly(const std::string name);
};

#endif
