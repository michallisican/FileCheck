#include "SearchFileFactory.h"
#include "SearchingParallel.h"
#include "SearchInFileRegex.h"

SearchingParallel::~SearchingParallel()
{
}

int SearchingParallel::PerformSearch()
{
	if (iSearchInFile::FileExists(_File))
	{
		_apIs.push_back((std::shared_ptr <iSearchInFile>) SearchFileFactory::SearchMethode(_SearchingMethode));
		_tv.push_back(std::thread(&iSearchInFile::SearchInFile, _apIs.back(), _File, _Word));
	}
	else
		for (auto& a_path : std::experimental::filesystem::recursive_directory_iterator(_File))
			if (iSearchInFile::FileExists(a_path.path().string()))
			{
				_apIs.push_back((std::shared_ptr <iSearchInFile>) SearchFileFactory::SearchMethode(_SearchingMethode));
				_tv.push_back(std::thread(&iSearchInFile::SearchInFile, _apIs.back(), a_path.path().string(), _Word));
			}

	for (unsigned int i = 0; i < _tv.size(); i++)
		if (_tv[i].joinable())
			_tv[i].join();

	return 0;
}
