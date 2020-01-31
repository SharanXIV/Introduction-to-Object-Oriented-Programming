//***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// Filename:          graph.h
// Date:	          2018/05/18
// Author:	          Sharan Shanmugaratnam
// Description:
// A workshop designed to help us with compiling and linking 
// modular programs.
//***********************************************************************

#ifndef SICT_GRAPH_H
#define SICT_GRAPH_H

#define MAX_NO_OF_SAMPLES 20

namespace sict {

	void getSamples(int samples[], int noOfSamples);
	int findMax(int samples[], int noOfSamples);
	void printGraph(int samples[], int noOfSamples);
	void printBar(int val, int max);
}
#endif