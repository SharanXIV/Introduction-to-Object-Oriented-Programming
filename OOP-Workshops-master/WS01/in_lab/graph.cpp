//***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// Filename:          graph.cpp
// Date:	          2018/05/18
// Author:	          Sharan Shanmugaratnam
// Description:
// A workshop designed to help us with compiling and linking 
// modular programs.
//***********************************************************************

#include <iostream>
#include "tools.h"
#include "graph.h"
using namespace std;
namespace sict {

	// Fills the samples array with the statistic samples
	//
	void getSamples(int samples[], int noOfSamples) {
		int i;
		for (i = 0; i < noOfSamples; i++) {
			cout << (i + 1) << "/" << noOfSamples << ": ";
			samples[i] = getInt(1, 1000000);
		}
	}

	// finds the largest sample in the samples array, if it is larger than 70,
	// otherwise it will return 70. 
	//
	int findMax(int samples[], int noOfSamples) {
		int max = samples[0];
		int i;
		for (i = 1; i < noOfSamples; i++) {
			if (max < samples[i]) max = samples[i];
		}
		return max < 70 ? 70 : max;
	}

	// prints a graph comparing the sample values visually 
	//
	void printGraph(int samples[], int noOfSamples) {
		int max = findMax(samples, noOfSamples);
		cout << "Graph:" << endl;
		for (int i = 0; i < noOfSamples; i++) {
			printBar(samples[i], max);
		}
	}
	// prints a scaled bar relevant to the maximum value in samples array
	//
	void printBar(int val, int max) {
		int i;
		for (i = 0; i < 70 * val / max; i++) {
			cout << "*";
		}
		cout << " " << val << endl;
	}
}