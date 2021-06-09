#pragma once
#include "TransactionNode.h"

class BST
{
public:
	BST();
	~BST();

	// getters
	Node* getRoot() const;

	// setters
	void setRoot(Node* newRoot);

	void insert(int newUnits, std::string newData);

	void inOrderTraversal();

	TransactionNode& findSmallest();

	TransactionNode& findLargest();


private:
	Node* mpRoot;


	void insert(Node*& pTree, int newUnits, std::string newData);

	void inOrderTraversal(Node* pTree);

	void destroyTree(Node* pTree);

};