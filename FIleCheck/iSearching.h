
#ifndef I_SEARCH
#define I_SEARCH

#include <iostream>
#include <fstream>
#include <experimental\filesystem>
#include <string>
#include <vector>
#include <mutex>
#include <regex>
#include <memory>
#include <chrono>
//#include "iSearchInFile.h"

enum SearchMethode
{
	regex_m = 1,
	substr_m,
	substr2_m,
	all_m,
};

enum SearchType
{
	sequential_t = 1,
	parallel_t,
	all_t,
};

class iSearchInFile;
class SearchFileFactory;

#pragma once
class iSearching
{
private:
	std::string PrefixSufixMaker(std::string TextIn, unsigned int MaxPos, bool begin);
protected:
	std::vector<std::thread> _vector_of_threads;
	std::vector<std::shared_ptr <iSearchInFile>> _vector_of_shared_pointers_for_searching;
	std::string _File;
	std::string _Word;
	int _SearchingMethod;
	int _SearchingType;
	virtual int PerformSearch() = 0;
public:
	iSearching() { _SearchingMethod = regex_m; _SearchingType = substr_m; };
	iSearching(int methode, int type) { _SearchingMethod = methode; _SearchingType = type; };
	~iSearching() {};
	int Start(std::string file, std::string word);
};

#endif // I_SEARCH
