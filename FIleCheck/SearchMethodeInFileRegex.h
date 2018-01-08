#ifndef SEARCH_IN_FILE_REGEX
#define SEARCH_IN_FILE_REGEX

#include <mutex>
#include <regex>
#include <vector>
#include "iSearchMethodeInFile.h"

#pragma once
class SearchMethodeInFileRegex : public iSearchMethodeInFile
{
private:
	std::mutex myMutex;
	std::vector<LineFilePrefix> lfp;
public:
	SearchMethodeInFileRegex() {};
	~SearchMethodeInFileRegex() {};
	void SearchMethodeInFile(std::string file_name, std::string key);
	std::vector<LineFilePrefix> GetResults();
};


#endif // !SEARCH_IN_FILE_REGEX
