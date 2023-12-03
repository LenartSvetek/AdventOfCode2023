#include "DayThree.h"

bool checkIfAdjSym(std::vector<std::string>& board, int x, int y) {
	size_t minX = (x != 0) ? x - 1 : x;
	size_t maxX = (x != board[y].length() - 1) ? x + 1 : x;
	size_t minY = (y != 0) ? y - 1 : y;
	size_t maxY = (y != board.size() - 1) ? y + 1 : y;


	for (int yi = minY; yi <= maxY; yi++) {
		for (int xi = minX; xi <= maxX; xi++) {
			char ch = board[yi].at(xi);
			
			if (ch != '.' && (ch < '0' || ch > '9')) return true;
		}
	}

	return false;
}

gear checkIfAdjNum(std::vector<std::string>& board, size_t x, size_t y) {
	size_t minX = (x != 0) ? x - 1 : x;
	size_t maxX = (x != board[y].length() - 1) ? x + 1 : x;
	size_t minY = (y != 0) ? y - 1 : y;
	size_t maxY = (y != board.size() - 1) ? y + 1 : y;

	gear Gear;
	for (int yi = minY; yi <= maxY; yi++) {
		for (int xi = minX; xi <= maxX; xi++) {
			char ch = board[yi].at(xi);

			if ((ch >= '0' && ch <= '9')) {
				if (Gear.numOfNums == 0) {
					Gear.x1 = xi;
					Gear.y1 = yi;
				}
				else {
					Gear.x2 = xi;
					Gear.y2 = yi;
				}
				Gear.numOfNums++;
				xi = findLast(board[yi], xi);
			};
		}
	}
	
	return Gear;
}

size_t findStart(std::string& str, size_t i) {
	try {
		for (; i >= 0 && str.at(i) >= '0' && str.at(i) <= '9'; i--) std::cout << i << " ";
	}
	catch(int x){
		std::cout << i << std::endl;		
	}
	return i + 1;
}

size_t findLast(std::string& str, size_t i)
{
	for (; i < str.length() && str.at(i) >= '0' && str.at(i) <= '9'; i++);
	return i - 1;
}

long partNumber() {
	std::vector<std::string> engineSCH = Helper::readFile("Assets/DayThree.txt");
	long sum = 0;
	for (size_t i = 0; i < engineSCH.size(); i++) {
		std::string str = engineSCH[i];

		for (size_t j = 0; j < str.length(); j++) {
			if (str.at(j) >= '0' && str.at(j) <= '9' && checkIfAdjSym(engineSCH, j, i)) {
				size_t firstI = findStart(str, j);
				size_t lastI = findLast(str, j);
				std::string snum = str.substr(firstI, lastI - firstI + 1);

				sum += std::stoi(snum);
				j = lastI;

			};
		}
	}

	return sum;
}

long partNumberPartTwo()
{
	std::vector<std::string> engineSCH = Helper::readFile("Assets/DayThree.txt");
	long sum = 0;
	for (size_t i = 0; i < engineSCH.size(); i++) {
		std::string str = engineSCH[i];

		for (size_t j = 0; j < str.length(); j++) {
			gear Gear = checkIfAdjNum(engineSCH, j, i);
			if (str.at(j) == '*' && Gear.numOfNums == 2) {
				size_t firstI1 = findStart(engineSCH[Gear.y1], Gear.x1);
				size_t lastI1 = findLast(engineSCH[Gear.y1], Gear.x1);
				std::string snum1 = engineSCH[Gear.y1].substr(firstI1, lastI1 - firstI1 + 1);

				size_t firstI2 = findStart(engineSCH[Gear.y2], Gear.x2);
				size_t lastI2 = findLast(engineSCH[Gear.y2], Gear.x2);
				std::string snum2 = engineSCH[Gear.y2].substr(firstI2, lastI2 - firstI2 + 1);
				std::cout << "stoi: " << snum1 << " " << snum2 << std::endl;
				sum += std::stoi(snum1) * std::stoi(snum2);

			};
		}
	}

	return sum;
}
