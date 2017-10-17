#include "iSearchInFile.h"
#include "SearchInFileRegex.h"
#include "SearchInFileSubstr.h"
#include "SearchInFileSubstr2.h"
#include "SearchFileFactory.h"

std::shared_ptr<iSearchInFile> SearchFileFactory::SearchMethode(int choice)
{
	if (choice == regex_m)
		
		return std::make_shared<SearchInFileRegex>();
	else if (choice == substr_m)
		return std::make_shared<SearchInFileSubstr>();
	else if (choice == substr2_m)
		return std::make_shared<SearchInFileSubstr2>();
	else
	{
		throw std::exception("SearchFileFactory::SearchMethode: methode not found!!!\n");
		return nullptr; //std::make_shared<SearchInFileSubstr>();
	}
}
