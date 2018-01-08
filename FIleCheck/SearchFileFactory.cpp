#include "iSearchMethodeInFile.h"
#include "SearchMethodeInFileRegex.h"
#include "SearchMethodeInFileSubstr.h"
#include "SearchMethodeInFileSubstr2.h"
#include "SearchFileFactory.h"

std::shared_ptr<iSearchMethodeInFile> SearchFileFactory::SearchMethode(int choice)
{
	if (choice == regex_m)
		
		return std::make_shared<SearchMethodeInFileRegex>();
	else if (choice == substr_m)
		return std::make_shared<SearchMethodeInFileSubstr>();
	else if (choice == substr2_m)
		return std::make_shared<SearchMethodeInFileSubstr2>();
	else
	{
		throw std::exception("SearchFileFactory::SearchMethode: methode not found!!!\n");
		return nullptr;
	}
}
