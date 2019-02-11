#include <string>
using namespace std;

typedef enum { ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION } FUNCTIONS;

//class for nodes in the CalcList linked list
class CalcNode
{
    private:
        double elem;
        CalcNode* next;
        double totalCopy;
        double operandCopy;
        string operationSign;

        friend class CalcList;
};


//class for linked list that inherits pure virtual functions from the CalcListInterface class
class CalcList
{
    public:
        CalcList();
        ~CalcList();
        bool empty() const;
        double total() const;
        void newOperation(const FUNCTIONS func, const double operand);
        void removeLastOperation();
        string toString(unsigned short precision) const;
        void printList();
        int sizeOf() const;
    
    private:
        CalcNode* head;
        double totalTemp;

};
