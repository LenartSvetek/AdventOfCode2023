#include "DayFour.h"

long winnings() {
	std::vector<std::string> cards = Helper::readFile("Assets/DayFour.txt");

	long sum = 0;
	for (size_t i = 0; i < cards.size(); i++) {
		std::vector<std::string> sets = Helper::split(cards[i], '|');
		std::vector<std::string> set1 = Helper::split(sets[0], ' ', 2);
		std::vector<std::string> set2 = Helper::split(sets[1], ' ');
		
		int num = 0;
		for (size_t j = 0; j < set1.size(); j++) {
			for (size_t ii = 0; ii < set2.size(); ii++) {
				
				if (set1[j] == set2[ii] && set1[j] != "") {
					num++;
					break;
				}
			}
		}

		sum += (num > 0) ? (long)std::pow(2, num - 1) : 0;
	}

	return sum;
}

long getWinnigs(std::vector<std::string>& cards, size_t start, size_t offset, long sum) {
	for (size_t i = start + 1; i < start + offset + 1; i++) {
		std::vector<std::string> sets = Helper::split(cards[i], '|');
		std::vector<std::string> set1 = Helper::split(sets[0], ' ', 2);
		std::vector<std::string> set2 = Helper::split(sets[1], ' ');
		/*
		for (size_t ii = 0; ii < set1.size(); ii++) {
			std::cout << "\"" << set1[ii] << "\" ";
		}
		std::cout << std::endl;

		for (size_t ii = 0; ii < set2.size(); ii++) {
			std::cout << "\"" << set2[ii] << "\" ";
		}
		std::cout << std::endl;
		*/

		int num = 0;
		for (size_t ii = 0; ii < set1.size(); ii++) {
			for (size_t iii = 0; iii < set2.size(); iii++) {
				//std::cout << set1[ii] << " " << set2[iii];
				if (set1[ii] == set2[iii]) {
					num++;
					break;
				}
				//std::cout << std::endl;
			}
		}
		std::cout << i + 1 << " " << start + 1 << " " << start + offset + 1 << " " << num << std::endl;
		sum = getWinnigs(cards, i, num, sum);
		
	}

	return sum + 1;
}

long winningsPartTwo() {
	std::vector<std::string> cards = Helper::readFile("Assets/DayFour.txt");
	long sum = 0;
	sum = getWinnigs(cards, -1, 6, sum);

	return sum;
}