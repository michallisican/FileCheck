#include "SearchInFileSubstr.h"

void SearchInFileSubstr::SearchInFile(std::string file_name, std::string key)
{
	std::ifstream file;

	if (!FileExists(file_name))
	{
		std::cout << file_name << " is not file\n";
	}
	
	file.open(file_name);
	if (file.is_open())
	{
		std::string line;
		std::size_t found;
		int j = 0;
		int i = 0;
		int pos_tmp = key.length();
		std::string pos = "";


		for (; getline(file, line); i++)
		{
			pos_tmp -= key.length();
			found = line.find(key);
			for (; !line.empty() && ((found) != std::string::npos); j++)
			{
				pos_tmp += found + key.length();
				pos += std::to_string(i) + ":" + std::to_string(pos_tmp) + ", ";
				line.erase(0, found + key.length());
			}

			if (line.empty() || ((found) == std::string::npos))
			{
				pos_tmp = 0;
			}
		}

		file.close();

		if (!pos.empty())
		{
			std::lock_guard<std::mutex> guard(myMutex);
			lfp.push_back(LineFilePrefix(file_name, "[" + pos.erase(pos.length() - 2, pos.length()) + "]"));
		}
	}
	else
		std::cout << "File is not open\n";
}


std::vector<LineFilePrefix> SearchInFileSubstr::GetResults()
{
	std::vector<LineFilePrefix> ret;

	std::lock_guard<std::mutex> guard(myMutex);
	ret = lfp;

	return ret;
}
