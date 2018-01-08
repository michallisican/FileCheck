#include "SearchMethodeInFileRegex.h"

void SearchMethodeInFileRegex::SearchMethodeInFile(std::string file_name, std::string key)
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
		std::string pos = "";
		std::regex re(key);
		int i = 0;

		for (; getline(file, line); i++)
		{
			try
			{
				std::sregex_iterator next(line.begin(), line.end(), re);
				std::sregex_iterator end;
				while (next != end) {
					std::smatch match = *next;
					pos += std::to_string(i) + ":" + std::to_string(match.position()) + ", ";
					next++;
				}

			}
			catch (const std::exception& e)
			{
				std::cout << "File: " << file_name << " ERROR: " << e.what() << std::endl;
				file.close();
				return;
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
		std::cout << "File " << file_name << " is not open\n";
}


std::vector<LineFilePrefix> SearchMethodeInFileRegex::GetResults()
{
	std::vector<LineFilePrefix> ret;

	std::lock_guard<std::mutex> guard(myMutex);
	ret = lfp;
	return ret;
}
