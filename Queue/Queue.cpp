#include <iostream>
using namespace std;

class queue
{

    public:
        queue(int size)
        {
            _size = size;
            _numElements = 0;
            _arrPtr = NULL;
            _arrPriorityPtr = NULL;
        }
        ~queue()
        {
            delete[] _arrPtr;
            delete[] _arrPriorityPtr;
        }
        void enqueue(int value,int priority)
        {
            if(_numElements < _size)
            {
                if(_numElements == 0)
                {
                    _arrPtr = new int[++_numElements];
                    _arrPriorityPtr = new int[_numElements];
                    _arrPtr[_numElements - 1] = value;
                    _arrPriorityPtr[_numElements - 1] = priority;
                }
                else
                {
                    int temp[_numElements];
                    int tempPriority[_numElements];
                    int currentNumElement = _numElements;
                    for(int i = 0; i < _numElements;i++)
                    {
                        temp[i] = _arrPtr[i];
                        tempPriority[i] = _arrPriorityPtr[i];
                    }
                    delete[] _arrPtr;
                    delete[] _arrPriorityPtr;
                    _arrPtr = new int[++_numElements];
                    _arrPriorityPtr = new int[_numElements];
                    int maxIndex = _numElements - 1;
                    //finding the priority position
                    for(int i = currentNumElement - 1; i >= 0 ; i--)
                    {
                        if(tempPriority[i] < priority)
                        {
                            maxIndex = i;
                        }
                    }
            
                    for(int i = 0; i < maxIndex;i++)
                    {
                        _arrPtr[i] = temp[i];
                        _arrPriorityPtr[i] = tempPriority[i];
                    }
                    _arrPtr[maxIndex] = value;
                    _arrPriorityPtr[maxIndex] = priority;
                    for(int i = maxIndex + 1; i < _numElements;i++)
                    {
                        _arrPtr[i] = temp[i - 1];
                        _arrPriorityPtr[i] = tempPriority[i - 1];
                    }
                }
            }
            else{
                cout << "the queue is full!\n";
            }
        }
        void enqueue(int value)
        {
            enqueue(value,0);
        }
        int dequeue()
        {
            if(_numElements == 0)
            {
                cout << "the queue is empty";
                return 0;
            }
            else{
                
                int temp[_numElements];
                int tempPriority[_numElements];
                int currentNumElement = _numElements;
                for(int i = 0; i < _numElements;i++)
                {
                    temp[i] = _arrPtr[i];
                    tempPriority[i] = _arrPriorityPtr[i];
                }
                delete[] _arrPtr;
                delete[] _arrPriorityPtr;
                _arrPtr = new int[--_numElements];
                _arrPriorityPtr = new int[_numElements];
                for(int i = 1; i < currentNumElement;i++)
                {
                    _arrPtr[i - 1] = temp[i];
                    _arrPriorityPtr[i - 1] = tempPriority[i];
                }
                return temp[0];
            }
        }
        void displayElement()
        {
            for(int i = 0; i < _numElements;i++)
            {
                cout << _arrPtr[i] << " ";
            }
            cout << endl;
        }
    private:
        int* _arrPtr;
        int* _arrPriorityPtr;
        int  _size;
        int  _numElements;
};
int main()
{
    queue q(100);
    for(int i = 0; i < 3;i++)
    {
        q.enqueue(i);
    }
    cout << "queue q: " << endl;
    q.displayElement();
    cout << "dequeue " << q.dequeue() << endl;
    cout << "queue after dequeuing\n";
    q.displayElement();
    q.enqueue(0,1);
    cout << "after enqueue 0 with priroity\n";
    q.displayElement();
    q.enqueue(4,1);
    cout << "after enqueue 4 with priroity\n";
    q.displayElement();
    return 0;
}