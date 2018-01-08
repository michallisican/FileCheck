#ifndef SEARCH_IN_FILE_SUBSTR
#define SEARCH_IN_FILE_SUBSTR

#include <mutex>
#include <vector>
#include <string>
#include "iSearchMethodeInFile.h"

#pragma once
class SearchMethodeInFileSubstr : public iSearchMethodeInFile
{
private:
	std::mutex myMutex;
	std::vector<LineFilePrefix> lfp;
public:
	SearchMethodeInFileSubstr() {};
	~SearchMethodeInFileSubstr() {};
	void SearchMethodeInFile(std::string file_name, std::string key);
	std::vector<LineFilePrefix> GetResults();
};

#endif // !SEARCH_IN_FILE_SUBSTR
