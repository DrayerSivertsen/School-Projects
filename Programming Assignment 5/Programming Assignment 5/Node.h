#pragma once
#include "Data.h"

class QueueNode
{
public: // Member functions
    QueueNode(Data* newData);

    QueueNode(const QueueNode& copy);

    ~QueueNode();

    // getters
    Data* getData() const;
    QueueNode* getNextPtr() const;

    // setters
    void setData(Data* newData);
    void setNextPtr(QueueNode* const pNewNext);

private:

    Data* pData;    // The memory for Data will need to be allocated on the heap as well!

    QueueNode* pNext;

};

std::ostream& operator<< (std::ostream& lhs, QueueNode*& rhs);
