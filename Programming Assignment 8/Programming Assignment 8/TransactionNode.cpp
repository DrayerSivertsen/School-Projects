#include "TransactionNode.h"

TransactionNode::TransactionNode(std::string newData, int newUnits):Node(newData)
{
	this->setData(newData);

	mUnits = newUnits;

}

TransactionNode::~TransactionNode()
{

}

// getters
int TransactionNode::getUnits() const
{
	return mUnits;
}

// setters
void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

void TransactionNode::printData()
{
	std::cout << this->getUnits() << ", " << this->getData() << std::endl;
}