/*
	Programming Language C++

	Programming Assignment 5: Grocery Store Simulation

	Programmer: Drayer Sivertsen
	Date Created: 3/13/21
	Last Modified: 3/13/21

	Description: We’ve all had the pleasant experience of standing 
	in line at the grocery store. As I’m standing in line I’m always 
	trying to figure out if I chose the line with the fastest service. 
	In most cases, I fail miserably. Let’s write a program to simulate
	two lines in a grocery store, which will allow us to better 
	understand how to select the fastest line.

*/

#include "Queue.h"
#include "testQueue.h"

int
main(void)
{
	testQueue test;

	test.testEnqueueEmpty();
	test.testEnqueueNotEmpty();
	test.testDequeueOneNode();
	test.testDequeueTwoNodes();
	test.runSimulation();
	

	

	return 0;
}