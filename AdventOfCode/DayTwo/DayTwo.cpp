#include "DayTwo.h"

long sumOfPossibleGames() {
	std::vector<std::string> games = Helper::readFile("Assets/DayTwo.txt");

	long possibleGames = 0;
	for (size_t i = 0; i < games.size(); i++) {
		std::vector<std::string> split = Helper::split(games[i], ' ');

		bool bPossible = true;
		for (size_t j = 2; j < split.size() && bPossible; j += 2) {
			std::string color = (split[j + 1].at(split[j + 1].length() - 1) == ';' || split[j + 1].at(split[j + 1].length() - 1) == ',') ? split[j + 1].substr(0, split[j + 1].length() - 1) : split[j + 1];
			int stColor = std::stoi(split[j]);

			if (color == "red" && stColor > 12) bPossible = false;
			else if (color == "green" && stColor > 13) bPossible = false;
			else if (color == "blue" && stColor > 14) bPossible = false;
		}
		if (bPossible) {
			int num = std::stoi(split[1]);
			std::cout << num << std::endl;
			possibleGames += num;
		}

	}

	return possibleGames;
}


long sumOfPossibleGamesPartTwo() {
	std::vector<std::string> games = Helper::readFile("Assets/DayTwo.txt");

	long possibleGames = 0;
	for (size_t i = 0; i < games.size(); i++) {
		std::vector<std::string> split = Helper::split(games[i], ' ');

		int red = 0;
		int green = 0;
		int blue = 0;

		for (size_t j = 2; j < split.size(); j += 2) {
			std::string color = (split[j + 1].at(split[j + 1].length() - 1) == ';' || split[j + 1].at(split[j + 1].length() - 1) == ',') ? split[j + 1].substr(0, split[j + 1].length() - 1) : split[j + 1];
			int stColor = std::stoi(split[j]);

			if (color == "red" && stColor > red) red = stColor;
			else if (color == "green" && stColor > green) green = stColor;
			else if (color == "blue" && stColor > blue) blue = stColor;
		}
		long root = std::pow(std::pow(red, 3) * std::pow(green, 3) * std::pow(blue, 3), 1.0 / 3);
		
		possibleGames += root + 1;
	}

	return possibleGames;
}
