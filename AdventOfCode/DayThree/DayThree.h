#pragma once
#include "../Helpers.hpp"
#include <iostream>

struct gear {
	int x1 = -1;
	int y1 = -1;
	int x2 = -1;
	int y2 = -1;
	int numOfNums = 0;
};

bool checkIfAdjSym(std::vector<std::string>& board, int x, int y);
gear checkIfAdjNum(std::vector<std::string>& board, size_t x, size_t y);

size_t findStart(std::string& str, size_t i);
size_t findLast(std::string& str, size_t i);

long partNumber();
long partNumberPartTwo();