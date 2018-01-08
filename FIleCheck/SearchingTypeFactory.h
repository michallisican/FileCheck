#ifndef SEARCHING_FACTORY
#define SEARCHING_FACTORY

#pragma once
class SearchingTypeFactory
{
public:
	SearchingTypeFactory() {};
	~SearchingTypeFactory() {};
	static std::shared_ptr<iSearchingType> SearchType(int methode, int type);
};

#endif // !SEARCHING_FACTORY

