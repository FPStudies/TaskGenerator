/*
 * Random.cpp
 *
 *  Created on: Nov 15, 2019
 *      Author: filip
 */

#include "Random.hpp"
#include <chrono>
#include <vector>

taskgen::Random::Random()
{
	auto currentTime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	auto epoch = currentTime.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

	generator.seed(value.count());
}

std::vector<int> taskgen::Random::generate(int a, int b, int n)
{
	std::vector<int> Result;
	Result.resize(n);

	std::uniform_int_distribution<int> distribution(a,b);

	for (int i=0; i<n; ++i) Result[i] = distribution(generator);

	return Result;
}

int taskgen::Random::generate(int a, int b)
{
	std::uniform_int_distribution<int> distribution(a,b);

	return distribution(generator);
}

