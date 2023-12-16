#include <iostream>
using namespace std;

class circularQueue
{

    public:
        circularQueue(int size)
        {
            _size = size;
            _front = _rear = 0;
            _arrPtr = new int[_size];
        }
        ~circularQueue()
        {
            delete[] _arrPtr;
        }
        void enqueue(int value)
        {
            _rear = (_rear + 1) % _size;
            if(_front == _rear)
            {
                cout << "Queue is full!\n";
                _rear--;
            }
            else
            {
                _arrPtr[_rear] = value;
            }
        }
        int dequeue()
        {
            if(_front == _rear)
                cout << "Queue is empty!\n";
            else
            {
                _front = (_front + 1) % _size;
                int result = _arrPtr[_front];
                _arrPtr[_front] = 0;
                return result;     
            }
            return 0;
        }
        void displayElement()
        {
            for(int i = 0; i < _size;i++)
            {
                cout << _arrPtr[i] << " ";
            }
            cout << endl;
        }
    private:
        int* _arrPtr;
        int  _size;
        int _front;
        int _rear;
};
int main()
{
    circularQueue queue(4);//_zize = 4, capacity is size - 1 
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
     cout << "queue: \n";
    queue.displayElement();
    cout << "dq: " << queue.dequeue() << endl;
    cout << "dq: " << queue.dequeue() << endl;
    queue.enqueue(5);
    queue.enqueue(4);
    queue.enqueue(2);
    queue.displayElement();
    cout << "dq: " << queue.dequeue() << endl;
    queue.enqueue(6);
    queue.displayElement();
    cout << "dq: " << queue.dequeue() << endl;
    queue.enqueue(7);
    queue.displayElement();
    return 0;
}