#include "DayOne.h"

std::vector<std::string> calValueStr() {
	std::fstream puzzle("Assets/DayOne.txt");
	std::string text = "";
	std::vector<std::string> values;
	while (std::getline(puzzle, text)) values.push_back(text);
	return values;
}

long calibrationValue() {
	std::vector<std::string> values = calValueStr();
	
	long vsota = 0;

	for (size_t i = 0; i < values.size(); i++) {
		int First = -1;
		int Last = -1;
		std::string string = values[i];

		for (size_t j = 0; j < string.length() && (First == -1 || Last == -1); j++) {
			if (First == -1 && (int)string.at(j) >= 48 && (int)string.at(j) <= 57) {
				First = j; //(int)values[i].at(j) - 48
			}
			if (Last == -1 && (int)string.at(string.length() - 1 - j) >= 48 && (int)string.at(string.length() - 1 - j) <= 57) {
				Last = string.length() - 1 - j; // (int)values[i].at(values[i].length() - 1 - j) - 48;
			}
		}

		int vzpredi[9] = { string.find("one"), string.find("two"), string.find("three"), string.find("four"), string.find("five"), string.find("six"), string.find("seven"), string.find("eight"), string.find("nine") };
		int vzporedimin_i = 0;

		int vzadi[9] = { string.rfind("one"), string.rfind("two"), string.rfind("three"), string.rfind("four"), string.rfind("five"), string.rfind("six"), string.rfind("seven"), string.rfind("eight"), string.rfind("nine") };
		int vzporedimax_i = 0;

		for (size_t i = 0; i < 9; i++) {
			vzpredi[i] = vzpredi[i] == -1 ? string.length() : vzpredi[i];
			if (vzpredi[i] < vzpredi[vzporedimin_i]) vzporedimin_i = i;
			if (vzadi[i] > vzadi[vzporedimax_i]) vzporedimax_i = i;
		}

		First = (First != -1 && First < vzpredi[vzporedimin_i]) ? (int)string.at(First) - 48 : vzporedimin_i + 1;
		Last = (Last != -1 && Last > vzadi[vzporedimax_i]) ? (int)string.at(Last) - 48 : vzporedimax_i + 1;

		vsota += First * 10 + Last;
	}

	return vsota;
}
