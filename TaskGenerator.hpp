/*
 * TaskGenerator.hpp
 *
 *  Created on: Nov 15, 2019
 *      Author: filip
 */

#ifndef TASKGENERATOR_HPP_
#define TASKGENERATOR_HPP_

#include "Task.hpp"
#include "Random.hpp"
#include "GenProperties.hpp"

namespace taskgen
{

static int DEFAULT_EXECUTION_TIME_MAX = 20;
static int SWAP_FACTOR = 4;

class TaskGenerator
{
	GenProperties properties;
	Random randomGenerator;

	void shuffle(std::vector<Task>& TaskList);
	void delay(std::vector<Task>& TaskList);
public:

	TaskGenerator(int proc=DEFAULT_PROCESSORS, int task=DEFAULT_TASKS, int delay=DEFAULT_DELAY);
	TaskGenerator(const GenProperties& prop);
	~TaskGenerator(){};

	std::vector<Task> generate();
	int getProcessors() {return properties.processors;};
};

}

#endif /* TASKGENERATOR_HPP_ */
