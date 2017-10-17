#ifndef SEARCH_IN_FILE_REGEX
#define SEARCH_IN_FILE_REGEX

#include <mutex>
#include <regex>
#include <vector>
#include "iSearchInFile.h"

#pragma once
class SearchInFileRegex : public iSearchInFile
{
private:
	std::mutex myMutex;
	std::vector<LineFilePrefix> lfp;
public:
	SearchInFileRegex() {};
	~SearchInFileRegex() {};
	void SearchInFile(std::string file_name, std::string key);
	std::vector<LineFilePrefix> GetResults();
};


#endif // !SEARCH_IN_FILE_REGEX
