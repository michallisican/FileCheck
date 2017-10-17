#ifndef SEARCHING_FACTORY
#define SEARCHING_FACTORY

#pragma once
class SearchingFactory
{
public:
	SearchingFactory() {};
	~SearchingFactory() {};
	static std::shared_ptr<iSearching> SearchType(int methode, int type);
};

#endif // !SEARCHING_FACTORY

