/*
 * GenProperties.cpp
 *
 *  Created on: Nov 15, 2019
 *      Author: filip
 */

#include "GenProperties.hpp"

taskgen::GenProperties::GenProperties(int proc, int task, int delay)
{
	processors=proc;
	tasks=task;
	targetDelay=delay;
}


