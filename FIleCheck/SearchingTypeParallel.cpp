#include "SearchFileFactory.h"
#include "SearchingTypeParallel.h"
#include "SearchMethodeInFileRegex.h"

SearchingTypeParallel::~SearchingTypeParallel()
{
}

int SearchingTypeParallel::PerformSearch()
{
	// Check if parameter _File is file or directory 
	if (iSearchMethodeInFile::FileExists(_File)) // Parameter _File is file
	{
		// Push back method with search method for next use in thread
		_vector_of_shared_pointers_for_searching.push_back( SearchFileFactory::SearchMethode(_SearchingMethod));
		// Push back thread what use a member of iSearchMethodeInFile and function for this thread 
		_vector_of_threads.push_back(std::thread(&iSearchMethodeInFile::SearchMethodeInFile, _vector_of_shared_pointers_for_searching.back(), _File, _Word));
	}
	else // Parameter _File is directory
		for (auto& a_path : std::experimental::filesystem::recursive_directory_iterator(_File)) // Recursively check contents of a directory and its subdirectories
			if (iSearchMethodeInFile::FileExists(a_path.path().string())) // Check if parameter _File is file or directory 
			{
				// Push back method with search method for next use in thread
				_vector_of_shared_pointers_for_searching.push_back( SearchFileFactory::SearchMethode(_SearchingMethod));
				// Push back thread what use a member of iSearchMethodeInFile and function for this thread 
				_vector_of_threads.push_back(std::thread(&iSearchMethodeInFile::SearchMethodeInFile, _vector_of_shared_pointers_for_searching.back(), a_path.path().string(), _Word));
			}

	// Waiting for threads
	for (unsigned int i = 0; i < _vector_of_threads.size(); i++)
		if (_vector_of_threads[i].joinable())
			_vector_of_threads[i].join();

	return 0;
}
