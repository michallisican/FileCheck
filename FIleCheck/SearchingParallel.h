#ifndef SEARCHING_PARALLEL
#define SEARCHING_PARALLEL

#include "iSearching.h"

#pragma once
class SearchingParallel : public iSearching
{
public:
	SearchingParallel() { _SearchingMethode = regex_m; _SearchingType = parallel_t; };
	SearchingParallel(int methode, int type) { _SearchingMethode = methode; _SearchingType = type; };
	~SearchingParallel();
	int PerformSearch();
};

#endif // !SEARCHING_PARALLEL

