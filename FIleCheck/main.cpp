#include <memory>
#include <iostream>
#include <string>
#include "iSearching.h"
#include "SearchingFactory.h"

void Start( std::string File, std::string Word, int methode, int type )
{
	std::shared_ptr <iSearching> search;
	try
	{
		search = (std::shared_ptr <iSearching>) SearchingFactory::SearchType(methode, type);
		search->Start(File, Word);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Help()
{
	std::cout << "SINTAX:\n [searching methode] [searching type] [path_to_directory_or_file] [searching_word]\n";
	std::cout << "searching methode: -r = searching with regular expresions, -s = searching with substring methode, -s2 = searching with second substring methode\n";
	std::cout << "searching type: -p = parallel (multithread) seatching, -s = serial (regular) seatching\n";
}


int main(int argc, char *argv[])
{
	std::string Word = "Michal";
	std::string File = "Testtt";
	int methode = regex_m;
	int type = parallel_t;
	

	/*if (argc <= 1 || ((std::string) argv[1]).compare("-h") == 0 || ((std::string) argv[1]).compare("--help") == 0)
	{
		Help();
		return 0;
	}
	else if (((std::string) argv[1]).compare("-r") == 0)
	{
		methode = regex_m;
	}
	else if (((std::string) argv[1]).compare("-s") == 0)
	{
		methode = substr_m;
	}
	else if (((std::string) argv[1]).compare("-s2") == 0)
	{
	methode = substr2_m;
	}
	else
	{
		Help();
		return 0;
	}

	if (((std::string) argv[2]).compare("-p") == 0)
	{
		type = parallel_t;
	}
	else if (((std::string) argv[2]).compare("-s") == 0)
	{
		type = regular_t;
	}
	else
	{
		Help();
		return 0;
	}

	if (!((std::string) argv[3]).empty())
		File = argv[3];
	else
		Help();

	if (!((std::string) argv[4]).empty())
		Word = argv[4];
	else
		Help();*/

	std::cout << "---------------------------------------------------Round 1\n";
	
	Start(File, Word, 12, parallel_t);

	Start(File, Word, regex_m, 55);

	Start(File, Word, regex_m, parallel_t);

	Start(File, Word, substr_m, parallel_t);

	Start(File, Word, substr2_m, parallel_t);

	Start(File, Word, regex_m, sequential_t);

	Start(File, Word, substr_m, sequential_t);

	Start(File, Word, substr2_m, sequential_t);

	getchar();

	return 0;
}