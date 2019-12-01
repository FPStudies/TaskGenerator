/*
 * GenProperties.hpp
 *
 *  Created on: Nov 15, 2019
 *      Author: filip
 */

#ifndef GENPROPERTIES_HPP_
#define GENPROPERTIES_HPP_

namespace taskgen
{

static int DEFAULT_PROCESSORS=5;
static int DEFAULT_TASKS=20;
static int DEFAULT_DELAY=0;

class GenProperties
{
public:
	int processors;
	int tasks;
	int targetDelay;

	GenProperties(int proc=DEFAULT_PROCESSORS, int task=DEFAULT_TASKS, int delay=DEFAULT_DELAY);
	~GenProperties(){};
};


}

#endif /* GENPROPERTIES_HPP_ */
