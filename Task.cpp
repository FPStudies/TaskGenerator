/*
 * Task.cpp
 *
 *  Created on: Nov 15, 2019
 *      Author: filip
 */

#include "Task.hpp"

taskgen::Task::Task(int exT, int dedl, int proc, int stT)
{
	executionTime=exT;
	deadline=dedl;
	processor=proc;
	startTime=stT;
}
