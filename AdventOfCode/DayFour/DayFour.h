#pragma once
#include "../Helpers.hpp"
#include <iostream>

long winnings();

long getWinnigs(std::vector<std::string>& cards, size_t start, size_t offset, long sum);
long winningsPartTwo();