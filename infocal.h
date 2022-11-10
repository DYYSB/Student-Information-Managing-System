#pragma once
#include "node.h"
#include "sort.h"
#include <iostream>
#include <string>
#include <vector>

int calAverage(_STUDENT*, int);
double passRate(_STUDENT*, int);
_STUDENT* searchMinAge(_STUDENT*);
void copyToSort(_STUDENT*, int);
void sortBy(std::vector<_STUDENT>*, int);