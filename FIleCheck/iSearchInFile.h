#ifndef I_SEARCH_FILE
#define I_SEARCH_FILE

#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include <thread>

struct LineFilePrefix
{
	std::string Position;
	std::string File;
	LineFilePrefix() : Position(""), File("")
	{
	}

	LineFilePrefix(std::string FileIn, std::string PositionIn) : Position(""), File("")
	{
		Position = PositionIn;
		File = FileIn;
	}
};

//namespace fs = std::experimental::filesystem;

#pragma once
class iSearchInFile
{
public:
	iSearchInFile();
	virtual void SearchInFile(std::string file_name, std::string key) = 0;
	virtual std::vector<LineFilePrefix> GetResults() = 0;
	static bool FileExists(std::string FileName);
};

#endif // !I_SEARCH_FILE

