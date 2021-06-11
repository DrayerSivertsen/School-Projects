#pragma once
#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class Data
{
public: // Member functions
    Data(int newCustomerNumber = 0, int newServiceTime = 0, int newTotalTime = 0);

    Data(const Data& copy);

    ~Data();

    // getters
    int getCustomerNumber() const;
    int getServiceTime() const;
    int getTotalTime() const;

    // setters
    void setCustomerNumber(const int newCustomerNumber);
    void setServiceTime(const int newServiceTime);
    void setTotalTime(const int newTotalTime);

    //Data* operator=(const Data*& rhs);

private:

    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1

    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes

    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

}; // This memory needs to be allocated on the heap!

