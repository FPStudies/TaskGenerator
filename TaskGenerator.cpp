/*
 * TaskGenerator.cpp
 *
 *  Created on: Nov 15, 2019
 *      Author: filip
 */

#include "TaskGenerator.hpp"

taskgen::TaskGenerator::TaskGenerator(const GenProperties& prop)
{
properties=prop;
}

taskgen::TaskGenerator::TaskGenerator(int proc, int task, int delay)
{
properties.processors=proc;
properties.tasks=task;
properties.targetDelay=delay;
}

void taskgen::TaskGenerator::delay(std::vector<Task>& TaskList)
{
	int j=properties.targetDelay;
	int hj=j;

	while (j!=0)
	{
		std::vector<int> Delays = randomGenerator.generate(0, properties.tasks-1, j);
		j=0;

		for (unsigned int i=0; i<Delays.size(); ++i) {
			if (TaskList[Delays[i]].deadline>TaskList[Delays[i]].executionTime) --TaskList[Delays[i]].deadline;
			else ++j;
		}

		if (j==hj) break; //cannot apply the delay
		hj=j;
	}

}

void taskgen::TaskGenerator::shuffle(std::vector<Task>& TaskList)
{
	std::vector<int> Swap1 = randomGenerator.generate(0, properties.tasks-1, taskgen::SWAP_FACTOR*properties.tasks);
	std::vector<int> Swap2 = randomGenerator.generate(0, properties.tasks-1, taskgen::SWAP_FACTOR*properties.tasks);

	for (int i=0; i<taskgen::SWAP_FACTOR*properties.tasks; ++i) {
		std::iter_swap(TaskList.begin()+Swap1[i], TaskList.begin()+Swap2[i]);
	}
}

std::vector<taskgen::Task> taskgen::TaskGenerator::generate()
{
	std::vector<taskgen::Task> TaskList;
	TaskList.resize(properties.tasks);

	std::vector<int> ExecutionTimes = randomGenerator.generate(1, taskgen::DEFAULT_EXECUTION_TIME_MAX, properties.tasks);
	std::vector<int> Processors = randomGenerator.generate(0, properties.processors-1, properties.tasks);

	std::vector< std::vector<int> > ProcessorList;
	ProcessorList.resize(properties.processors);

	for (int i=0; i<properties.tasks; ++i)
	{
		TaskList[i].executionTime=ExecutionTimes[i];
		TaskList[i].processor=Processors[i];

		ProcessorList[Processors[i]].push_back(i);

			int stTime=0;
			for (unsigned int j=0; j<ProcessorList[Processors[i]].size()-1; ++j){
				stTime+=TaskList[ProcessorList[Processors[i]][j]].executionTime;
			}
			TaskList[i].startTime=stTime;

		TaskList[i].deadline=TaskList[i].startTime+TaskList[i].executionTime;
	}

	this->delay(TaskList);
	this->shuffle(TaskList);

	return TaskList;
}
