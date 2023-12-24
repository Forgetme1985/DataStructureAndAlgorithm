#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
};
class circularlyLinkedList
{
    public:
    circularlyLinkedList()
    {
        _listHead = NULL;
    }
    ~circularlyLinkedList()
    {
       while(_listHead != NULL)
       {
            node* travelNode = _listHead;
            node* nodeHead = _listHead;
            while(travelNode->next != _listHead)
            {
                travelNode = travelNode->next;
            }
            if(travelNode != _listHead)
            {
                _listHead = _listHead->next;
                travelNode->next = _listHead;
                delete nodeHead;
            }
            else
            {
                break;
            }
       }
       delete _listHead;
    }
    void displayNodes()
    {
        node* temp =_listHead;
        while(temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
            if(temp == _listHead)
                break;
        }
        cout << endl;
    }
    node* getNode(int val)
    {
       node* temp = _listHead;
       while(temp != NULL && temp->value != val)
       {
            temp = temp->next;
       }
       return temp;
    }
    void removeNode()//remove the node on the left side
    {
        if(_listHead == NULL)
        {
            cout << "the list is empty\n";
            return;
        }
        else{
            node* travelNode = _listHead;
            node* temp = _listHead;
            while(travelNode->next != _listHead)
            {
                travelNode = travelNode->next;
            }
            travelNode->next = temp->next;
            delete temp;
            _listHead = travelNode->next;
        }
    }
    void addNode(int val)//add node on the right side
    {
        if(_listHead == NULL)
        {
            _listHead = new node;
            _listHead->value = val;
            _listHead->next = _listHead;
        }
        else{
           node* travelNode = _listHead;
           while(travelNode->next != _listHead)
           {
                travelNode = travelNode->next;
           }
           node* newNode = new node;
           newNode->value = val;
           travelNode->next = newNode;
           newNode->next = _listHead;
        }
    }
    void insertNode(int val,int k)
    {
        int count = 1;
        node* previousNode = _listHead;
        node* travelNode = _listHead;
        if(previousNode == NULL)
        {
            cout << "empty list!\n";
            return;
        }
        while(count < k)
        {
            count++;
            previousNode = travelNode;
            travelNode = travelNode->next;
        }
        node* newNode = new node;
        newNode->value = val;
        newNode->next = travelNode;
        previousNode->next = newNode;
    }
    

    private:
    node* _listHead;
};
int main()
{
    circularlyLinkedList list;
    list.addNode(3);
    list.addNode(2);
    list.addNode(1);
    list.displayNodes();// 3 2 1
    list.removeNode();
    list.displayNodes();// 2 1
    list.insertNode(3,3);
    list.displayNodes();// 2 1 3
    return 0;
}