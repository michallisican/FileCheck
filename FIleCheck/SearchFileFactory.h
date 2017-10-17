#ifndef SEARCH_FILE_FACTORY
#define SEARCH_FILE_FACTORY

#include "iSearching.h"

class iSearchInFile;

#pragma once
class SearchFileFactory
{
public:
	SearchFileFactory() {};
	~SearchFileFactory() {};
	static std::shared_ptr<iSearchInFile> SearchMethode(int choice = 1);

};

#endif // !SEARCH_FILE_FACTORY
