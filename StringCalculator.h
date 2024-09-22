#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <bits/stdc++.h>
using namespace std;

class StringCalculator
{
public:
int add(const std::string name);
private:
void prepareString(std::string name);
void checkForException(const std::string name);
void checkForNegativeInteger(const std::string name);
int checkUpperLimitsForInteger(const std::string name);
};

#endif
