#include <iostream>

using namespace std;

class stack
{
    public:
    stack(int n)
    {
        _numElements = 0;
        _size = n;
        _arrPtr = new int[_size];
    }
    stack(const stack& b)
    {
        _size = b._size;
        _arrPtr = new int[_size];
        _numElements = 0;
        for(int i = 0; i < b._numElements;i++)
        {
           _arrPtr[i] = b._arrPtr[i];
           _numElements++;
        }
    }
    ~stack()
    {
        delete[] _arrPtr;
    }
    void push(int v)
    {
        if(_numElements < _size)
        {
            _arrPtr[_numElements++] = v;
        }
        else
        {
            cout << "stack is full";
        }
    }
    int pop()
    {
        if(_numElements > 0)
        {
            int value = _arrPtr[--_numElements];
            return value;
        }
        else{
            cout << "stack is empty";
            return -1;
        }
    }
    void sort()
    {
        for(int i = 0; i < _numElements - 1;i++)
        {
            for(int j = i + 1; j < _numElements;j++)
            {
                if(_arrPtr[i] > _arrPtr[j])
                {
                    int temp = _arrPtr[i];
                    _arrPtr[i] = _arrPtr[j];
                    _arrPtr[j] = temp;
                }
            }
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
    stack operator+(stack b)
    {
        int newSize = _size + b.getSize();
        stack newStack(newSize);
        for(int i = 0; i < _numElements;i++)
        {
            newStack.push(_arrPtr[i]);
        }
        for(int j= 0; j < b.getNumElements();j++)
        {
            newStack.push(b.getValue(j));
        }
        return newStack;
       
    }
    stack operator=(stack b)
    {
        _size = b._size;
        _arrPtr = new int[_size];
        _numElements = 0;
        for(int i = 0; i < b._numElements;i++)
        {
           _arrPtr[i] = b._arrPtr[i];
           _numElements++;
        }
        return *this;
    }
    int getValue(int index)
    {
        if(index >=0 && index < _numElements)
            return _arrPtr[index];
        return -1;
    }
    int getSize()
    {
        return _size;
    }
    int getNumElements()
    {
        return _numElements;
    }
    private:
    int* _arrPtr;
    int _size;
    int _numElements;
};

int main()
{
    stack s(4);
    for(int i = 1; i <= 4; i++)
    {
        s.push(i);
    }

    stack s1(2);
    s1.push(-5);
    s1.push(-6);

    cout << "Before sorting: ";
    s.displayElement();
    cout << s.pop() << endl;
    cout << "After pop 1: ";
    s.displayElement();
    s.sort();
    cout << "After sorting: ";
    s.displayElement();
    cout << s.pop() << endl;
    cout << "After pop 2: ";
    s.displayElement();

    cout << "stack s: "; s.displayElement();
    cout << "stack s1: "; s1.displayElement();
    stack s2 = s  + s1;
    cout << "the merge stack: " ; s2.displayElement();
    s2.sort();
    cout << "the merge stack after sort: "; s2.displayElement();
    s2.pop();
    cout << "the merge stack after pop: ";
    s2.displayElement();
    return 0;
}