#include "iSearchMethodeInFile.h"



iSearchMethodeInFile::iSearchMethodeInFile()
{
}

bool iSearchMethodeInFile::FileExists(std::string FileName)
{
	std::ifstream test(FileName);
	return (test) ? true : false;
}
