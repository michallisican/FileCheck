
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
//#include "iSearchMethodeInFile.h"

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

class iSearchMethodeInFile;
class SearchFileFactory;

#pragma once
class iSearchingType
{
private:
	std::string PrefixSufixMaker(std::string TextIn, unsigned int MaxPos, bool begin);
protected:
	std::vector<std::thread> _vector_of_threads;
	std::vector<std::shared_ptr <iSearchMethodeInFile>> _vector_of_shared_pointers_for_searching;
	std::string _File;
	std::string _Word;
	int _SearchingMethod;
	int _SearchingType;
	virtual int PerformSearch() = 0;
public:
	iSearchingType() { _SearchingMethod = regex_m; _SearchingType = substr_m; };
	iSearchingType(int methode, int type) { _SearchingMethod = methode; _SearchingType = type; };
	~iSearchingType() {};
	int Start(std::string file, std::string word);
};

#endif // I_SEARCH
