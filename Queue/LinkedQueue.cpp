#include <iostream>
using namespace std;

struct node
{
    int value;
    node* next;
};
class linkedQueue
{
    public:
    linkedQueue()
    {
        _front = _rear = NULL;
    }
    ~linkedQueue()
    {
        while(_front !=NULL)
        {
            node* temp = _front;
            _front = _front->next;
            delete temp;
        }
    }
    void enqueue(int val)
    {
        if(_front == NULL && _rear == NULL)
        {
            _front = new node;
            _front->value = val;
            _rear = _front;
        }
        else
        {
            node* newNode = new node;
            newNode->value = val;
            if(_rear == _front)
            {
                _rear = newNode;
                _front->next = _rear;
            }
            else
            {
                _rear->next = newNode;
                _rear = newNode;
            }
        }
    }
    int dequeue()
    {
        if(_front == NULL && _rear == NULL)
        {
            cout << "queue is empty!\n";
            return 0;
        }
        else
        {
            node* temp = _front;
            int value = _front->value;
            _front = _front->next;
            delete temp;
            return value;
        }
    }
    private:
    node* _front;
    node* _rear;
};
int main()
{
    linkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.dequeue() << " ";// 1
    cout << queue.dequeue() << " ";// 1 2
    cout << queue.dequeue() << " ";// 1 2 3
    cout << endl;
    return 0;
}