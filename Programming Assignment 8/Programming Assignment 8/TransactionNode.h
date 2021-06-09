#pragma once
#include "Node.h"

class TransactionNode : public Node
{
public:
	TransactionNode(std::string newData = "", int newUnits = 0);
	~TransactionNode();

	// getters
	int getUnits() const;

	// setters
	void setUnits(int newUnits);


	void printData();

private:
	int mUnits;


};