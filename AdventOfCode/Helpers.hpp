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

	inline std::vector<std::string> combine(std::vector<std::string> vec, std::string on = "") {
		std::vector<std::string> combined;
		std::string tmp = "";
		for (size_t i = 0; i < vec.size(); i++) {
			if (vec[i] == "") {
				combined.push_back(tmp);
				tmp = "";
				continue;
			}
			tmp += vec[i] + "\n";
		}
		if (tmp != "") combined.push_back(tmp);

		return combined;
	};

	inline std::vector<std::string> split(std::string s, char del, size_t start = 0) {
		std::stringstream ss(s);
		std::string word;
		std::vector<std::string> split;
		int i = 0;
		while (!ss.eof()) {
			if(word != "") i++;
			std::getline(ss, word, del);
			if (i < start || word == "") continue;
			split.push_back(word);
		}

		return split;
	}
}