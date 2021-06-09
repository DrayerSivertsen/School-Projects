#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(mpRoot);
}

void BST::destroyTree(Node* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;

	}
}

// getters
Node* BST::getRoot() const
{
	return mpRoot;
}

// setters
void BST::setRoot(Node* newRoot)
{
	mpRoot = newRoot;
}

void BST::insert(int newUnits, std::string newData)
{
	insert(mpRoot, newUnits, newData);
}

void BST::insert(Node*& pTree, int newUnits, std::string newData)
{
	if (pTree == nullptr)
	{
		mpRoot = new TransactionNode(newData, newUnits);
	}
	else
	{
		if (newUnits < (dynamic_cast <TransactionNode*> (pTree))->getUnits())
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new TransactionNode(newData, newUnits));
			}
			else
			{
				insert(pTree->getLeftPtr(), newUnits, newData);
			}
		}
		else if (newUnits > (dynamic_cast <TransactionNode*> (pTree))->getUnits())
		{
			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new TransactionNode(newData, newUnits));
			}
			else
			{
				insert(pTree->getRightPtr(), newUnits, newData);
			}
		}
	}

	

}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

void BST::inOrderTraversal(Node* pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeftPtr());
		(dynamic_cast <TransactionNode*> (pTree))->printData();
		inOrderTraversal(pTree->getRightPtr());
	}
}

TransactionNode& BST::findSmallest()
{
	TransactionNode* pMem = (dynamic_cast <TransactionNode*> (this->mpRoot));
	
	TransactionNode smallest;

	while (pMem->getLeftPtr() != nullptr)
	{
		pMem = (dynamic_cast <TransactionNode*> (pMem->getLeftPtr()));
	}

	//smallest = *pMem;

	return *pMem;
}

TransactionNode& BST::findLargest()
{
	TransactionNode* pMem = (dynamic_cast <TransactionNode*> (this->mpRoot));

	TransactionNode largest;

	while (pMem->getRightPtr() != nullptr)
	{
		pMem = (dynamic_cast <TransactionNode*> (pMem->getRightPtr()));
	}


	return *pMem;
}