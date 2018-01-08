#ifndef SEARCHING_PARALLEL
#define SEARCHING_PARALLEL

#include "iSearchingType.h"

#pragma once
class SearchingTypeParallel : public iSearchingType
{
public:
	SearchingTypeParallel() { _SearchingMethod = regex_m; _SearchingType = parallel_t; };
	SearchingTypeParallel(int methode, int type) { _SearchingMethod = methode; _SearchingType = type; };
	~SearchingTypeParallel();
	int PerformSearch();
};

#endif // !SEARCHING_PARALLEL

