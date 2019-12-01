/*
 * Random.hpp
 *
 *  Created on: Nov 15, 2019
 *      Author: filip
 */

#ifndef RANDOM_HPP_
#define RANDOM_HPP_

#include <random>

namespace taskgen
{

class Random
{
	std::default_random_engine generator;

public:
	Random();
	~Random(){};


std::vector<int> generate(int a, int b, int n);
int generate (int a, int b);
};

}



#endif /* RANDOM_HPP_ */
