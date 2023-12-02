#pragma once
#include <vector>
#include <fstream>
#include <sstream>

namespace Helper {
	inline std::vector<std::string> readFile(std::string file) {
		std::fstream puzzle(file);
		std::string text = "";
		std::vector<std::string> values;
		while (std::getline(puzzle, text)) values.push_back(text);
		return values;
	}

	inline std::vector<std::string> split(std::string s, char del) {
		std::stringstream ss(s);
		std::string word;
		std::vector<std::string> split;
		while (!ss.eof()) {
			std::getline(ss, word, del);
			split.push_back(word);
		}

		return split;
	}
}