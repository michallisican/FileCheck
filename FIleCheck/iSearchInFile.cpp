#include "iSearchInFile.h"



iSearchInFile::iSearchInFile()
{
}

bool iSearchInFile::FileExists(std::string FileName)
{
	std::ifstream test(FileName);
	return (test) ? true : false;
}
