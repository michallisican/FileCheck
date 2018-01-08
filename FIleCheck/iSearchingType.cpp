#include "iSearchingType.h"
#include "iSearchMethodeInFile.h"
#include "SearchFileFactory.h"

std::string iSearchingType::PrefixSufixMaker(std::string TextIn, unsigned int MaxPos, bool begin)
{
	if (!TextIn.empty())
	{
		if (TextIn.length() <= MaxPos)
			return TextIn;
		else
		{
			if (begin)
				return TextIn.substr(0, MaxPos);
			else
				return TextIn.substr(TextIn.length() - MaxPos, TextIn.length());
		}
	}
	else
		return "String is empty";
}

int iSearchingType::Start(std::string File, std::string Word)
{

	std::string type = "";
	if (_SearchingType == sequential_t)
		type += "Sequential";
	else if (_SearchingType == parallel_t)
		type += "Parallel";
	else
		throw "ERROR: Undefined serching type";

	type += " ";

	if (_SearchingMethod == regex_m)
		type += "Regex";
	else if (_SearchingMethod == substr_m)
		type += "Substr";
	else if (_SearchingMethod == substr2_m)
		type += "Substr2";
	else
		throw "ERROR: Undefined serching method";
	
	std::cout << type << " START *************************************\n";

	_File = File;
	_Word = Word;
	_vector_of_shared_pointers_for_searching.clear();
	_vector_of_threads.clear();

	auto start_time = std::chrono::high_resolution_clock::now();

	try
	{
		PerformSearch();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}

	auto current_time = std::chrono::high_resolution_clock::now();
	
	for (unsigned int i = 0; i < _vector_of_shared_pointers_for_searching.size(); i++)
	{
		if (_vector_of_shared_pointers_for_searching[i].get() != nullptr)
		{
			for (LineFilePrefix tmp : _vector_of_shared_pointers_for_searching[i]->GetResults())
				std::cout << tmp.File << " " << tmp.Position << " " << PrefixSufixMaker(Word,3, true) << "..." << PrefixSufixMaker(Word, 3, false) << std::endl;
			_vector_of_shared_pointers_for_searching[i].reset();
		}
		else
			std::cout << "Pointer is nullptr\n";
	}

	std::cout << type << " has been running for " << std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() << " milliseconds" << std::endl;

	std::cout << type << " END *************************************\n";
	return 0;
}