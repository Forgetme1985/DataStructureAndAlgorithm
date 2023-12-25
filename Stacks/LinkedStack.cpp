#include <iostream>
using namespace std;

struct node
{
    int value;
    node* next;
};
class linkedStack
{
    public:
    linkedStack()
    {
        _top = NULL;
    }
    ~linkedStack()
    {
        while(_top != NULL)
        {
            node* temp = _top;
            _top = _top->next;
            delete temp;
        }
    }
    void push(int val)
    {
        if(_top == NULL)
        {
            _top = new node;
            _top->value = val; 
        }
        else
        {
            node* newNode = new node;
            newNode->value = val;
            newNode->next = _top;
            _top = newNode;
        }
    }
    int pop()
    {
        if(_top == NULL)
        {
            cout << "stack is empty!\n";
            return 0;
        }
        else
        {
            node* temp = _top;
            int value = _top->value;
            _top =_top->next;
            delete temp;
            return value;
        }
    }
    private:
    node* _top;
};
int main()
{
    linkedStack stack;
    stack.push(3);
    stack.push(2);
    stack.push(1);
    cout << stack.pop() << " ";// 1
    cout << stack.pop() << " ";// 1 2
    cout << stack.pop() << " ";// 1 2 3
    cout << endl;
    return 0;
}