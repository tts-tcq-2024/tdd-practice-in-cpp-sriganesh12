#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <bits/stdc++.h>
using namespace std;

class StringCalculator
{
public:
int add(string name);
private:
void prepareString(string& name);
void checkForException(const string item);
int getInteger(const string item);
void checkForNegativeInteger(const int value);
int checkUpperLimitsForInteger(const int value);
};

#endif
