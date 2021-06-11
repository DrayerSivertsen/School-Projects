#include "Node.h"

QueueNode::QueueNode(Data* newData)
{
	pData = new Data(newData->getCustomerNumber(), newData->getServiceTime(), newData->getTotalTime());
	pNext = nullptr;
}

QueueNode::QueueNode(const QueueNode& copy)
{
	pData = copy.pData;
	pNext = copy.pNext;
}

QueueNode::~QueueNode()
{
	delete pData;
}

// getters

Data* QueueNode::getData() const
{
	return pData;
}

QueueNode* QueueNode::getNextPtr() const
{
	return pNext;
}

// setters

void QueueNode::setData(Data* newData)
{
	pData->setCustomerNumber(newData->getCustomerNumber());
	pData->setServiceTime(newData->getServiceTime());
	pData->setTotalTime(newData->getTotalTime());
}

void QueueNode::setNextPtr(QueueNode* const pNewNext)
{
	pNext = pNewNext;
}

std::ostream& operator<< (std::ostream& lhs, QueueNode*& rhs)
{
	cout << "Customer Number: " << rhs->getData()->getCustomerNumber() << std::endl;
	cout << "Service Time: " << rhs->getData()->getServiceTime() << std::endl;
	cout << "Total Time: " << rhs->getData()->getTotalTime() << std::endl << std::endl;

	return lhs;
}