#ifndef SEARCHING_SEQUENTIAL
#define SEARCHING_SEQUENTIAL

#include "iSearchingType.h"

#pragma once
class SearchingTypeSequential: public iSearchingType
{
public:
	SearchingTypeSequential() { _SearchingMethod = regex_m; _SearchingType = sequential_t; };
	SearchingTypeSequential(int methode, int type) { _SearchingMethod = methode; _SearchingType = type; };
	~SearchingTypeSequential();
	int PerformSearch();
};

#endif // !SEARCHING_SEQUENTIAL

