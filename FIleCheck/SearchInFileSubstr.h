#ifndef SEARCH_IN_FILE_SUBSTR
#define SEARCH_IN_FILE_SUBSTR

#include <mutex>
#include <vector>
#include <string>
#include "iSearchInFile.h"

#pragma once
class SearchInFileSubstr : public iSearchInFile
{
private:
	std::mutex myMutex;
	std::vector<LineFilePrefix> lfp;
public:
	SearchInFileSubstr() {};
	~SearchInFileSubstr() {};
	void SearchInFile(std::string file_name, std::string key);
	std::vector<LineFilePrefix> GetResults();
};

#endif // !SEARCH_IN_FILE_SUBSTR
