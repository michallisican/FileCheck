#include "SearchFileFactory.h"
#include "SearchingSequential.h"
#include "SearchInFileRegex.h"

SearchingSequential::~SearchingSequential()
{
}


int SearchingSequential::PerformSearch()
{
	if (iSearchInFile::FileExists(_File))
	{
		_apIs.push_back((std::shared_ptr <iSearchInFile>) SearchFileFactory::SearchMethode(_SearchingMethode));
		_apIs.back()->SearchInFile(_File, _Word);
	}
	else
		for (auto& a_path : std::experimental::filesystem::recursive_directory_iterator(_File))
			if (iSearchInFile::FileExists(a_path.path().string()))
			{
				_apIs.push_back((std::shared_ptr <iSearchInFile>) SearchFileFactory::SearchMethode(_SearchingMethode));
				_apIs.back()->SearchInFile(a_path.path().string(), _Word);
			}

	return 0;
}
