#include <iostream>
using namespace std;

class dque
{

    public:
        dque(int size)
        {
            _size = size;
            _arrPtr = NULL;
            _midlle = _size / 2;
            _left = _right = _midlle;
            _arrPtr = new int[_size];
        }
        ~dque()
        {
            delete[] _arrPtr;
        }
        void enqueueLeft(int leftValue)
        {
            int shiftLeft = (_left - 1) % _size;
            if(shiftLeft < 0)
            {
                shiftLeft = _size - 1;
            }
            if(_arrPtr[shiftLeft] == 0)
            {
                _arrPtr[shiftLeft] = leftValue;
                _left = shiftLeft;
            }
            else
            {
                cout << "the queue is full!\n";
            }
        }
        void enqueueRight(int rightValue)
        {
           int shiftRight = (_right + 1 % _size);
           if(shiftRight == _size)
            {
                shiftRight = 0;
            }
            if(_arrPtr[shiftRight] == 0)
            {
                _arrPtr[shiftRight] = rightValue;
                _right = shiftRight;
            }
            else
            {
                cout << "the queue is full!\n";
            }
        }
        int dequeueLeft()
        {
            if(_arrPtr[_right] == 0 && _arrPtr[_left] == 0)
            {
                cout << "the queue is empty!\n";
                 _left = _right = _midlle;
                return 0;
            }
            else{
                if(_arrPtr[_left] != 0)
                {
                    int result = _arrPtr[_left];
                    _arrPtr[_left] = 0;
                    int shiftLeft = 0;
                    if(_left < _midlle)
                        shiftLeft = (_left + 1) % _size;
                    else if(_left > _midlle)
                        shiftLeft = (_left - 1) % _size;
                    if(shiftLeft == _size)
                        shiftLeft = 0;
                    else if(shiftLeft < 0)
                        shiftLeft = _size - 1;
                    _left = shiftLeft;
                    return result;
                }
                else{
                    _left--;
                    return dequeueLeft();
                }
            }
        }
        int dequeueRight()
        {
            if(_arrPtr[_left] == 0 && _arrPtr[_right] == 0)
            {
                cout << "the queue is empty!\n";
                _left = _right = _midlle;
                return 0;
            }
            else{
                if(_arrPtr[_right] != 0){
                    int result = _arrPtr[_right];
                    _arrPtr[_right] = 0;

                    int shiftRight = 0;
                    if(_right < _midlle)
                        shiftRight = (_right - 1) % _size;
                    else if(_right > _midlle)
                        shiftRight = (_right + 1) % _size;
                    if(shiftRight == _size)
                        shiftRight = 0;
                    else if(shiftRight < 0)
                        shiftRight = _size - 1;

                    _right = shiftRight;
                    return result;
                }
                else{
                    _right++;
                    return dequeueRight();
                }
            }
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
        int _left;
        int _right;
        int _midlle;
};
int main()
{
    dque q(6);
    q.enqueueLeft(1);
    q.displayElement();
    q.enqueueLeft(-1);
    q.displayElement();
    q.enqueueLeft(-2);
    q.displayElement();
    q.enqueueLeft(-3);
    q.displayElement();
    q.enqueueLeft(-4);
    q.displayElement();
    q.enqueueLeft(-5);
    q.displayElement();
    
    cout << "left " << q.dequeueLeft() << endl;
    q.displayElement();
    cout << "left " << q.dequeueLeft() << endl;
    q.displayElement();
    cout << "right " << q.dequeueRight() << endl;
    q.displayElement();
    cout << "right " << q.dequeueRight() << endl;
    q.displayElement();
    cout << "left " << q.dequeueLeft() << endl;
    q.displayElement();
    cout << "right " << q.dequeueRight() << endl;
    q.displayElement();
    cout << "right " << q.dequeueRight() << endl;
    q.displayElement();
    q.enqueueLeft(1);
    q.displayElement();
    return 0;
}