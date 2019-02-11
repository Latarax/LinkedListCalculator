#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "CalcList.hpp"
using namespace std;

//constructor that initializes the CalcList and the head and totalTemp variables
CalcList::CalcList() 
    : head(NULL), totalTemp(0) 
{}

//returns whether the CalcList is empty or not
bool CalcList::empty() const
{
    return head == NULL;
}

//destructor for CalcList
CalcList::~CalcList()
{
    while(!empty())
    {
        CalcNode* old = head;
        head = old->next;
        delete old;
    }
}

//returns the current total for the CalcList
double CalcList::total() const
{
    return totalTemp;
}

//adds a new operation (new node) to the linked list
void CalcList::newOperation(const FUNCTIONS func, const double operand)
{   
    //creates node for addition
    if(func == ADDITION)
    {
        CalcNode* operation = new CalcNode();
        operation->totalCopy = totalTemp;
        operation->operandCopy = operand;
        operation->operationSign = "+";
        totalTemp += operand;
        operation->elem = totalTemp;
        operation->next = head; 
        head = operation;

    }
    //creates node for subtraction
    else if(func == SUBTRACTION)
    {
        CalcNode* operation = new CalcNode();
        operation->totalCopy = totalTemp;
        operation->operandCopy = operand;
        operation->operationSign = "-";
        totalTemp -= operand;
        operation->elem = totalTemp;
        operation->next = head; 
        head = operation;
    }
    //creates node for multiplication
    else if(func == MULTIPLICATION)
    {
        CalcNode* operation = new CalcNode();
        operation->totalCopy = totalTemp;
        operation->operandCopy = operand;
        operation->operationSign = "*";
        totalTemp *= operand;
        operation->elem = totalTemp;
        operation->next = head; 
        head = operation;
    }
    //creates node for multiplication
    else if(func == DIVISION)
    {   
        //throws exception if user attempts to divide by zero
        if(operand == 0)
        {
            throw operand;
        }

        CalcNode* operation = new CalcNode();
        operation->totalCopy = totalTemp;
        operation->operandCopy = operand;
        operation->operationSign = "/";
        totalTemp /= operand;
        operation->elem = totalTemp;
        operation->next = head; 
        head = operation;
    }

    
}

//removes the last operation, which is at the front of the list
void CalcList::removeLastOperation()
{
    if(empty())
    {
        int x = 0;
        throw x;
    }
    else
    {
        CalcNode* old = head;
        head = old->next;
        delete old;
        
        if(sizeOf() == 0)
        {
            totalTemp = 0;
        }
        
        else
        {
            CalcNode* temp = new CalcNode();
            temp = head;
            totalTemp = temp->elem;
        }
    }
}

//formats the nodes of the CalcList and returns a formatted string
string CalcList::toString(unsigned short precision) const
{
    CalcNode* temp = new CalcNode();
    temp = head;
    ostringstream toS;
    if(temp->operationSign == "+")
    {

    }
    for(int j = sizeOf(); j >= 1; j--)
    {
        toS << setprecision(precision)<< fixed << showpoint;
        toS << j << ": " << temp->totalCopy << temp->operationSign << temp->operandCopy << "=" << temp->elem << endl;
        temp = temp->next;
    }

    return toS.str();
}

//prints the values of the CalcList
void CalcList::printList()
{
    CalcNode* temp = new CalcNode();
    temp = head;
    while(temp != NULL)
    {
        cout << "Value: " << temp->elem << endl;
        temp = temp->next;
    }
}

//returns the size of the CalcList
int CalcList::sizeOf() const
{
    CalcNode* temp = new CalcNode();
    temp = head;
    int i = 0;

    while(temp != NULL)
    {
        i++;
        temp = temp->next;
    }

    return i;
}

//main function can be modified to perform operations as needed
int main()
{
    try
    {
        CalcList calc;
        calc.newOperation(ADDITION, 10);
        calc.newOperation(MULTIPLICATION, 5);
        calc.newOperation(SUBTRACTION, 15);
        calc.newOperation(DIVISION, 7);
        calc.removeLastOperation();
        calc.removeLastOperation();
        calc.printList();

    }
    catch(...)
    {
        cout << "Error" << endl;
    }
    return 0;
}



