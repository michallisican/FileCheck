#include "iSearching.h"
#include "iSearchInFile.h"
#include "SearchFileFactory.h"

std::string iSearching::PrefixSufixMaker(std::string TextIn, unsigned int MaxPos, bool begin)
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

int iSearching::Start(std::string File, std::string Word)
{
	_File = File;
	_Word = Word;
	_apIs.clear();
	_tv.clear();

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

	std::string type = "";
	if (_SearchingType == sequential_t)
		type += "Sequential";
	else if (_SearchingType == parallel_t)
		type += "Parallel";

	type += " ";

	if (_SearchingMethode == regex_m)
		type += "Regex";
	else if (_SearchingMethode == substr_m)
		type += "Substr";
	else if (_SearchingMethode == substr2_m)
		type += "Substr2";
	
	/*std::cout << type << " has been running for " << std::chrono::duration_cast<std::chrono::minutes>(current_time - start_time).count() << " minutes" << std::endl;
	std::cout << type << " has been running for " << std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count() << " seconds" << std::endl;*/
	std::cout << type << " has been running for " << std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count() << " milliseconds" << std::endl;

	for (unsigned int i = 0; i < _apIs.size(); i++)
	{
		if (_apIs[i].get() != nullptr)
		{
			for (LineFilePrefix tmp : _apIs[i]->GetResults())
				std::cout << tmp.File << " " << tmp.Position << " " << PrefixSufixMaker(Word,3, true) << "..." << PrefixSufixMaker(Word, 3, false) << std::endl;
			_apIs[i].reset();
		}
		else
			std::cout << "Pointer is nullptr\n";
	}

	std::cout << "END\n";
	return 0;
}