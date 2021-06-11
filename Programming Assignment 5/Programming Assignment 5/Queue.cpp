#include "Queue.h"

Queue::Queue()
{
	pHead = nullptr;
	pTail = nullptr;
}

Queue::Queue(const Queue& copyQueue)
{
	QueueNode* pCur = copyQueue.getHeadPtr();
	QueueNode* pTemp = this->pHead;

	if (copyQueue.getHeadPtr() != nullptr)
	{
		QueueNode* pMem = new QueueNode(pCur->getData());

		this->pHead = pMem;

		pCur = pCur->getNextPtr();

		while (pCur != copyQueue.getTailPtr())
		{
			QueueNode* pMem = new QueueNode(pCur->getData());

			pMem->setData(pCur->getData());

			pTemp->setNextPtr(pMem);

			pCur = pCur->getNextPtr();
			pTemp = pTemp->getNextPtr();
		}
	}
}

Queue::~Queue()
{
	destroyQueue();
}

void Queue::destroyQueue()
{
	QueueNode* pMem = pHead;
	QueueNode* pDelete = nullptr;

	if (pMem != pTail)
	{
		pDelete = pMem;
		pMem = pMem->getNextPtr();

		delete pDelete;
	}
}


// getters

QueueNode* Queue::getHeadPtr() const
{
	return pHead;
}

QueueNode* Queue::getTailPtr() const
{
	return pTail;
}

// setters

void Queue::setHeadPtr(QueueNode* const pNewHead)
{
	pHead = pNewHead;
}

void Queue::setTailPtr(QueueNode* const pNewTail)
{
	pTail = pNewTail;
}

bool Queue::enqueue(Data* newData)
{
	QueueNode* pMem = nullptr;
	bool success = false;

	pMem = new QueueNode(newData);

	if (pMem != nullptr)
	{
		success = true;

		// empty
		if (this->pHead == nullptr)
		{
			this->pHead = this->pTail = pMem;

		}
		else // non empty
		{
			this->pTail->setNextPtr(pMem);
			this->pTail = pMem;
		}
	}


	return success;
}

Data* Queue::dequeue()
{
	QueueNode* pTemp = this->pHead;

	Data* copyData();

	if (this->pHead == this->pTail) 
	{
		this->pHead = this->pTail = nullptr;
	}
	else 
	{
		this->pHead = this->pHead->getNextPtr();
	}

	Data* pMem = new Data;

	pMem->setCustomerNumber(pTemp->getData()->getCustomerNumber());
	pMem->setServiceTime(pTemp->getData()->getServiceTime());
	pMem->setTotalTime(pTemp->getData()->getTotalTime());

	delete pTemp; 

	return pMem;
}

bool Queue::isEmpty()
{
	return this->pHead == nullptr;
}

void Queue::printQueue(Queue groceryLine)
{
	QueueNode* temp = groceryLine.getTailPtr();

	while (temp != nullptr)
	{
		cout << temp;

		temp = temp->getNextPtr();

	}


}

void Queue::runSimulation(void)
{
	int minutes = 0, n = 0, arrivalTimeNormal = 0, arrivalTimeExpress = 0;

	int customerNumberNormal = 0, customerNumberExpress = 0;

	int serviceNormal = 0, serviceExpress = 0;

	cout << "Enter the number of minutes you would like to run the simulation: ";
	cin >> n;

	Queue normal, printNormal;
	Queue express, printExpress;

	customerNumberNormal = 1;
	customerNumberExpress = 1;

	int lastTotalNormal = 0, lastTotalExpress = 0;

	Data* newData1;
	Data* newData2;


	for (int time = 0; time < n; ++time)
	{
		if (normal.isEmpty())
		{
			arrivalTimeNormal = (rand() % 6) + 3;

			newData1 = new Data(customerNumberNormal, (rand() % 6) + 3, 0);
			normal.enqueue(newData1);

			++customerNumberNormal;
		}
		else if (arrivalTimeNormal == 0)
		{

			if (normal.getTailPtr()->getData()->getCustomerNumber() == 1)
			{
				cout << "*Normal Lane*" << endl;
				cout << "Customer Number: " << normal.getTailPtr()->getData()->getCustomerNumber() << endl;
				cout << "Arrival Time: " << time << endl << endl;
			}
			
			if (serviceNormal == -1)
			{
				cout << "*Normal Lane*" << endl;
				cout << "Customer Number: " << normal.getTailPtr()->getData()->getCustomerNumber() << endl;
				cout << "Arrival Time: " << time << endl << endl;

				serviceNormal = normal.getTailPtr()->getData()->getServiceTime();
			}
			

			if (serviceNormal == 0)
			{
				normal.getTailPtr()->getData()->setTotalTime(lastTotalNormal += normal.getTailPtr()->getData()->getServiceTime());


				cout << "*Normal Lane*" << endl;
				cout << "Customer Number: " << normal.getTailPtr()->getData()->getCustomerNumber() << endl;
				cout << "Total Time: " << normal.getTailPtr()->getData()->getTotalTime() << endl << endl;

				newData1 = normal.dequeue();

				printNormal.enqueue(newData1);

				serviceNormal = -1;

			}
		}

		if (express.isEmpty())
		{
			arrivalTimeExpress = (rand() % 6) + 3;

			newData2 = new Data(customerNumberExpress, (rand() % 6) + 3, 0);
			express.enqueue(newData2);

			++customerNumberExpress;
		}
		else if (arrivalTimeExpress == 0)
		{
			if (express.getTailPtr()->getData()->getCustomerNumber() == 1)
			{
				cout << "*Express Lane*" << endl;
				cout << "Customer Number: " << express.getTailPtr()->getData()->getCustomerNumber() << endl;
				cout << "Arrival Time: " << time << endl << endl;
			}

			if (serviceExpress == -1)
			{
				cout << "*Express Lane*" << endl;
				cout << "Customer Number: " << express.getTailPtr()->getData()->getCustomerNumber() << endl;
				cout << "Arrival Time: " << time << endl << endl;

				serviceExpress = express.getTailPtr()->getData()->getServiceTime();
			}

			if (serviceExpress == 0)
			{
				express.getTailPtr()->getData()->setTotalTime(lastTotalExpress += express.getTailPtr()->getData()->getServiceTime());


				cout << "*Express Lane*" << endl;
				cout << "Customer Number: " << express.getTailPtr()->getData()->getCustomerNumber() << endl;
				cout << "Total Time: " << express.getTailPtr()->getData()->getTotalTime() << endl << endl;

				newData2 = express.dequeue();

				printExpress.enqueue(newData2);

				serviceExpress = -1;

			}
		}
		

		if (time % 10 == 0)
		{
			cout << "Normal Line History: " << std::endl;
			QueueNode* temp = printNormal.getHeadPtr();

			while (temp != nullptr)
			{
				cout << temp;

				temp = temp->getNextPtr();

			}

			cout << "Express Line History: " << std::endl;
			temp = printExpress.getHeadPtr();

			while (temp != nullptr)
			{
				cout << temp;

				temp = temp->getNextPtr();

			}
		}

		// increments
		if (arrivalTimeNormal > 0)
		{
			--arrivalTimeNormal;
		}
		if (arrivalTimeExpress > 0)
		{
			--arrivalTimeExpress;
		}
		if (serviceNormal > 0)
		{
			--serviceNormal;
		}
		if (serviceExpress > 0)
		{
			--serviceExpress;
		}
		
		
	}
}