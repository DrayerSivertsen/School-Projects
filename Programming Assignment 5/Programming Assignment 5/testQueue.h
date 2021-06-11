#pragma once
#include "Queue.h"

class testQueue
{
public:
	void testEnqueueEmpty(void);
	void testEnqueueNotEmpty(void);

	void testDequeueOneNode(void);
	void testDequeueTwoNodes(void);
/*
Function: Run Simulation
Date Created: 3/13/21
Date Last Modified: 3/20/21
Description: The function runs the simulation as a test case of 24 hours
Input Parameters: None
Returns: None
Preconditions: User enters 1440
Postconditions: None
*/
	void runSimulation(void);

private:
	

};