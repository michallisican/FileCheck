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
		_vector_of_shared_pointers_for_searching.push_back( SearchFileFactory::SearchMethode(_SearchingMethod));
		_vector_of_shared_pointers_for_searching.back()->SearchInFile(_File, _Word);
	}
	else
		for (auto& a_path : std::experimental::filesystem::recursive_directory_iterator(_File))
			if (iSearchInFile::FileExists(a_path.path().string()))
			{
				_vector_of_shared_pointers_for_searching.push_back( SearchFileFactory::SearchMethode(_SearchingMethod));
				_vector_of_shared_pointers_for_searching.back()->SearchInFile(a_path.path().string(), _Word);
			}

	return 0;
}
