#ifndef SEARCHING_SEQUENTIAL
#define SEARCHING_SEQUENTIAL

#include "iSearching.h"

#pragma once
class SearchingSequential: public iSearching
{
public:
	SearchingSequential() { _SearchingMethode = regex_m; _SearchingType = sequential_t; };
	SearchingSequential(int methode, int type) { _SearchingMethode = methode; _SearchingType = type; };
	~SearchingSequential();
	int PerformSearch();
};

#endif // !SEARCHING_SEQUENTIAL

