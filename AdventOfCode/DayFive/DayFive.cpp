#include "DayFive.h"

unsigned int getLocation(std::vector<std::vector<std::vector<unsigned long>>>& maps, int seed, int step) {
	int location = 0;
	for (int i = 0; i < maps[step].size(); i++) {
		if (maps[step][i][1] <= seed && seed < maps[step][i][1] + maps[step][i][2]) {
			if (step + 1 == maps.size()) {
				location = maps[step][i][0];
				break;
			}
			location = getLocation(maps, maps[step][i][0], step + 1);
			break;
		}
	}

	return location;
}

int lowestLocation() {
	std::vector<std::string> mapsStr = Helper::combine(Helper::readFile("Assets/DayFive.txt"));
	std::vector<std::string> numStr = Helper::split(mapsStr[0], ' ', 1);
	numStr[numStr.size() - 1].pop_back();
	std::vector<unsigned long> num(numStr.size());
	for (size_t i = 0; i < numStr.size(); i++) {
		std::cout << numStr[i] << " ";
		num[i] = std::stoul(numStr[i]);
		std::cout << num[i] << " ";
		
	}
	std::cout << std::endl << std::endl;
	 
	std::vector<std::vector<std::vector<unsigned long>>> maps;
	for (size_t i = 1; i < mapsStr.size(); i++) {
		std::vector<std::vector<unsigned long>> vec;
		std::vector<std::string> str = Helper::split(mapsStr[i], '\n', 1);
		for (size_t j = 0; j < str.size(); j++)
		{
			vec.push_back(std::vector<unsigned long>());
			std::vector<std::string> nums = Helper::split(str[j], ' ');
			for (size_t k = 0; k < nums.size(); k++){
				vec[j].push_back(std::stoul(nums[k]));
			}
		}
		maps.push_back(vec);
	}

	for (size_t i = 0; i < maps.size(); i++) {
		for (size_t j = 0; j < maps[i].size(); j++) {
			for (size_t k = 0; k < maps[i][j].size(); k++)
			{
				std::cout << maps[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (size_t i = 0; i < num.size(); i++)
	{
		std::cout << "Location of seed " << num[i] << ": " << getLocation(maps, num[i], 1) << std::endl;
	}

	return 0;
}
