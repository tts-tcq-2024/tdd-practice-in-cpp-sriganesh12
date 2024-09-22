#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <bits/stdc++.h>
using namespace std;

class StringCalculator
{
public:
int add(const string name);
private:
void prepareString(string& name);
void checkForException(const string item);
void checkForNegativeInteger(const string item);
int checkUpperLimitsForInteger(const string item);
};

#endif
