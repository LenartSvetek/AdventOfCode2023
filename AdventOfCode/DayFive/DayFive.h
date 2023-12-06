#pragma once

#include "../Helpers.hpp"
#include <iostream>

unsigned int getLocation(std::vector<std::vector<std::vector<unsigned long>>>& maps, int seed, int step = 0);
int lowestLocation();