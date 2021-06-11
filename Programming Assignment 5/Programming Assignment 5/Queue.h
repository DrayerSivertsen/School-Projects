#pragma once
#include "Node.h"

class Queue
{
public: // Member functions
    Queue();

    Queue(const Queue& copyQueue);

    ~Queue();

    // getters
    QueueNode* getHeadPtr() const;
    QueueNode* getTailPtr() const;

    // setters
    void setHeadPtr(QueueNode* const pNewHead);
    void setTailPtr(QueueNode* const pNewTail);

    bool enqueue(Data* newData);
    Data* dequeue();
/*
Function: Run simulation
Date Created: 3/13/21
Date Last Modified: 3/20/21
Description: The function runs the simulation for a user entered amount of time
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: None
*/
    void runSimulation(void);
/*
Function: Print Queue
Date Created: 3/13/21
Date Last Modified: 3/20/21
Description: The function prints the input queue
Input Parameters: Queue
Returns: None
Preconditions: None
Postconditions: None
*/
    void printQueue(Queue groceryLine);
/*
Function: Is empty
Date Created: 3/13/21
Date Last Modified: 3/20/21
Description: The function checks to see if the queue is empty
Input Parameters: None
Returns: bool true if queue is empty othewise false
Preconditions: None
Postconditions: None
*/
    bool isEmpty();


private:
/*
Function: Destroy queue
Date Created: 3/13/21
Date Last Modified: 3/20/21
Description: The function destroys the queue
Input Parameters: None
Returns: None
Preconditions: None
Postconditions: Queue memeory deleted
*/
    void destroyQueue();

    QueueNode* pHead;

    QueueNode* pTail;

};