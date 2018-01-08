#ifndef SEARCH_FILE_FACTORY
#define SEARCH_FILE_FACTORY

#include "iSearchingType.h"

class iSearchMethodeInFile;

#pragma once
class SearchFileFactory
{
public:
	SearchFileFactory() {};
	~SearchFileFactory() {};
	static std::shared_ptr<iSearchMethodeInFile> SearchMethode(int choice = 1);

};

#endif // !SEARCH_FILE_FACTORY
