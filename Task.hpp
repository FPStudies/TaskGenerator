/*
 * Task.hpp
 *
 *  Created on: Nov 15, 2019
 *      Author: filip
 */

#ifndef TASK_HPP_
#define TASK_HPP_

namespace taskgen
{

class Task
{
public:
	int executionTime;
	int deadline;

	int processor;
	int startTime;

	Task(int exT=1, int dedl=1, int proc=1, int stT=1);
	~Task(){};
};

}



#endif /* TASK_HPP_ */
