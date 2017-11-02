#include "SearchInFileSubstr2.h"

void SearchInFileSubstr2::SearchInFile(std::string file_name, std::string key)
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
		int i = 0;
		std::string pos = "";

		try
		{
			for (; getline(file, line); i++)
			{
				unsigned int j = 0;
				if (!line.empty() && (((int)(line.length() - key.length())) >= 0))
					for (; j <= line.length() - key.length(); ++j)
						if (key.compare(line.substr(j, key.length())) == 0)
							pos += std::to_string(i) + ":" + std::to_string(j) + ", ";
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "File: " << file_name << " ERROR: " << e.what() << std::endl;
			file.close();
			return ;
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


std::vector<LineFilePrefix> SearchInFileSubstr2::GetResults()
{
	std::vector<LineFilePrefix> ret;

	std::lock_guard<std::mutex> guard(myMutex);
	ret = lfp;

	return ret;
}
