#include "SearchFileFactory.h"
#include "SearchingTypeSequential.h"
#include "SearchMethodeInFileRegex.h"

SearchingTypeSequential::~SearchingTypeSequential()
{
}


int SearchingTypeSequential::PerformSearch()
{
	if (iSearchMethodeInFile::FileExists(_File))
	{
		_vector_of_shared_pointers_for_searching.push_back( SearchFileFactory::SearchMethode(_SearchingMethod));
		_vector_of_shared_pointers_for_searching.back()->SearchMethodeInFile(_File, _Word);
	}
	else
		for (auto& a_path : std::experimental::filesystem::recursive_directory_iterator(_File))
			if (iSearchMethodeInFile::FileExists(a_path.path().string()))
			{
				_vector_of_shared_pointers_for_searching.push_back( SearchFileFactory::SearchMethode(_SearchingMethod));
				_vector_of_shared_pointers_for_searching.back()->SearchMethodeInFile(a_path.path().string(), _Word);
			}

	return 0;
}
