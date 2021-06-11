#include "testQueue.h"

void testQueue::testEnqueueEmpty(void)
{
	Queue test;

	Data* newData = new Data(3, 5, 8);

	bool success = false;

	success = test.enqueue(newData);

	cout << "***Testing Enqueue Empty***" << endl;

	if (success == true)
	{
		cout << "Enqueue return value successful" << endl;

		if (test.getHeadPtr() != nullptr)
		{
			cout << "Enqueue head pointer successful" << endl;

			if (test.getTailPtr() != nullptr)
			{
				cout << "Enqueue tail pointer successful" << endl;

				if (!test.isEmpty())
				{
					cout << "Enqueue Successful!" << endl << endl;
				}
			}
		}
	}
}

void testQueue::testEnqueueNotEmpty(void)
{
	bool success = false;

	Queue test;
	Data* newData1 = new Data(3, 5, 8);
	test.enqueue(newData1);

	QueueNode* pMem = test.getTailPtr();

	Data* newData2 = new Data(4, 5, 9);
	success = test.enqueue(newData2);

	cout << "***Testing Enqueue One Node***" << endl;
	
	if (success == true)
	{
		cout << "Enqueue return value successful" << endl;

		if (test.getHeadPtr() != test.getTailPtr())
		{
			cout << "Enqueue head pointer successful" << endl;

			if (test.getTailPtr() != pMem)
			{
				cout << "Enqueue tail pointer successful" << endl;

				if (!test.isEmpty())
				{
					cout << "Enqueue Successful!" << endl << endl;
				}
			}
		}
	}
}

void testQueue::testDequeueOneNode(void)
{
	Queue test;

	Data* newData = new Data(3, 5, 8);

	bool success = false;

	success = test.enqueue(newData);

	cout << "***Testing Dequeue One Node***" << endl;

	newData = test.dequeue();

	if (newData->getCustomerNumber() == 3 && newData->getServiceTime() == 5
		&& newData->getTotalTime() == 8)
	{
		cout << "Dequeue return values successful" << endl;

		if (test.isEmpty())
		{
			cout << "Dequeue memory deletion was successful" << endl;

			cout << "Dequeue Successful!" << endl << endl;
		}
	}
}

void testQueue::testDequeueTwoNodes(void)
{
	bool success = false;

	Queue test;
	Data* newData1 = new Data(3, 5, 8);
	test.enqueue(newData1);

	Data* newData2 = new Data(4, 5, 9);
	success = test.enqueue(newData2);

	cout << "***Testing Dequeue Two Node***" << endl;

	newData1 = test.dequeue();

	if (newData1->getCustomerNumber() == 3 && newData1->getServiceTime() == 5
		&& newData1->getTotalTime() == 8)
	{
		cout << "Dequeue return values for first node successful" << endl;

		if (!test.isEmpty())
		{
			cout << "Dequeue memory deletion for first node was successful" << endl;

			cout << "Dequeue for first node Successful!" << endl << endl;
		}
	}

	newData2 = test.dequeue();

	if (newData2->getCustomerNumber() == 4 && newData2->getServiceTime() == 5
		&& newData2->getTotalTime() == 9)
	{
		cout << "Dequeue return values for second node successful" << endl;

		if (test.isEmpty())
		{
			cout << "Dequeue memory deletion for second node was successful" << endl;

			cout << "Dequeue for second node Successful!" << endl << endl;
		}
	}
}

void testQueue::runSimulation(void)
{
	Queue test;

	test.runSimulation();
}