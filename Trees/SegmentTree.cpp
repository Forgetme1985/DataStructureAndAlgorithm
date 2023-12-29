#include <iostream>
using namespace std;

struct node
{
    int value;
    int lowIndex;
    int highIndex;
};

class segmentTree
{
    public:
    segmentTree(int arr[],int size)
    {
        _totalNodes = 2 * (size - 1);
       _arrptr = new node[_totalNodes];

       _arrptr[1].lowIndex = 1;
       _arrptr[1].highIndex = size - 1;
       _arrptr[1].value = calculateProduct(_arrptr[1],arr);

       for(int i = 2; i < _totalNodes;i++)
       {
            int n = (_arrptr[ i / 2].highIndex - _arrptr[ i / 2].lowIndex) / 2;
            if(i % 2 == 0)
            {
                _arrptr[i].lowIndex = _arrptr[i / 2].lowIndex;
                _arrptr[i].highIndex = _arrptr[i / 2].lowIndex + n;
                _arrptr[i].value = calculateProduct(_arrptr[i],arr);
            }
            else
            {

                _arrptr[i].lowIndex = _arrptr[ i / 2].lowIndex + n + 1;
                _arrptr[i].highIndex = _arrptr[i / 2].highIndex;
                _arrptr[i].value = calculateProduct(_arrptr[i],arr);
            }
            cout << "indexNode: " << i << " low: " << _arrptr[i].lowIndex << " high: " <<_arrptr[i].highIndex << endl;
       }
    }
    ~segmentTree()
    {
        delete[] _arrptr;
    }
   
   void displayTree()
   {
        for(int i =1; i < _totalNodes;i++)
        {
            cout << _arrptr[i].value << " ";
        }
        cout << endl;
   }
   int querryNode(int nodeIndex,int l, int r)
   {
        if(r < _arrptr[nodeIndex].lowIndex || l > _arrptr[nodeIndex].highIndex)
            return 1;
        if(l <= _arrptr[nodeIndex].lowIndex && _arrptr[nodeIndex].highIndex <= r)
            return _arrptr[nodeIndex].value;
        int leftQ = querryNode(2 * nodeIndex,l,r);
        int rightQ = querryNode(2 * nodeIndex + 1,l,r);
        return (leftQ * rightQ);
   }
   void updateNode(int nodeIndex, int index, int value)
   {
        if(_arrptr[nodeIndex].lowIndex == _arrptr[nodeIndex].highIndex)
            _arrptr[nodeIndex].value = value;
        else
        {
            int mid = (_arrptr[nodeIndex].lowIndex + _arrptr[nodeIndex].highIndex) / 2;
            if(_arrptr[nodeIndex].lowIndex <= index && index <= mid)
                updateNode(2 * nodeIndex,index,value);
            else
                updateNode(2 * nodeIndex + 1, index, value);
            _arrptr[nodeIndex].value = _arrptr[2 * nodeIndex].value * _arrptr[2 * nodeIndex + 1].value;
        }
   }
    private:
    int calculateProduct(node n, int arr[])
    {
        int product = 1;
        for(int i = n.lowIndex; i <= n.highIndex;i++)
        {
             product *= arr[i];
        }
        return product;
    }
    private:
    node* _arrptr;
    int _totalNodes;
};
int main()
{
    const int SIZE = 8;
    int arr[SIZE];
    arr[0] = 0;
    arr[1] = 15;
    arr[2] = 5;
    arr[3] = 10;
    arr[4] = 6;
    arr[5] = 8;
    arr[6] = 1;
    arr[7] = 9;
    segmentTree tree(arr,SIZE);
    tree.displayTree();// 324000 4500 72 75 60 8 9 15 5 10 6 8 1
    cout << "Querry 2-5: " << tree.querryNode(1,2,5); //2400
    cout << endl;
    tree.updateNode(1,6,12);
    tree.displayTree();//3888000 4500 864 75 60 96 9 15 5 10 6 8 12
    cout << endl;
    return 0;
}