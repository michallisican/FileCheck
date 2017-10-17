#ifndef SEARCH_IN_FILE_SUBSTR2
#define SEARCH_IN_FILE_SUBSTR2


#include <mutex>
#include <vector>
#include <string>
#include "iSearchInFile.h"

#pragma once
class SearchInFileSubstr2 : public iSearchInFile
{
private:
	std::mutex myMutex;
	std::vector<LineFilePrefix> lfp;
public:
	SearchInFileSubstr2() {};
	~SearchInFileSubstr2() {};
	void SearchInFile(std::string file_name, std::string key);
	std::vector<LineFilePrefix> GetResults();
};

#endif // !SEARCH_IN_FILE_SUBSTR2

