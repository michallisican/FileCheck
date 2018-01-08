#ifndef SEARCH_IN_FILE_SUBSTR2
#define SEARCH_IN_FILE_SUBSTR2


#include <mutex>
#include <vector>
#include <string>
#include "iSearchMethodeInFile.h"

#pragma once
class SearchMethodeInFileSubstr2 : public iSearchMethodeInFile
{
private:
	std::mutex myMutex;
	std::vector<LineFilePrefix> lfp;
public:
	SearchMethodeInFileSubstr2() {};
	~SearchMethodeInFileSubstr2() {};
	void SearchMethodeInFile(std::string file_name, std::string key);
	std::vector<LineFilePrefix> GetResults();
};

#endif // !SEARCH_IN_FILE_SUBSTR2

