//============================================================================
// Name        : TaskGenerator.cpp
// Author      : Filip Przybysz
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TaskGenerator.hpp"

using namespace std;

int main(int argc, char** argv) {
	int tproc, ttask, tdelay;
	taskgen::TaskGenerator* TaskGen;
	vector<taskgen::Task> Tasks;

	tproc=ttask=tdelay=-1;
/*
	cout<<"Processors:"<<"\n";
	cin>>tproc;
	cout<<"Tasks:"<<"\n";
	cin>>ttask;
	cout<<"Target delay:"<<"\n";
	cin>>tdelay;
*/

	tproc=atoi(argv[1]);
	ttask=atoi(argv[2]);
	tdelay=atoi(argv[3]);

	if (tproc<1 || ttask<1 || tdelay<0) TaskGen = new taskgen::TaskGenerator();
	else TaskGen = new taskgen::TaskGenerator(tproc, ttask, tdelay);

	Tasks = TaskGen->generate();

	//cout<<TaskGen->getProcessors()<<"\n";
	for (unsigned int i=0; i<Tasks.size(); ++i)	{
	cout<<Tasks[i].executionTime<<" "<<Tasks[i].deadline;
	//cout<<" "<<Tasks[i].processor<<" "<<Tasks[i].startTime;
	cout<<"\n";
	}

	delete TaskGen;
	return 0;
}
