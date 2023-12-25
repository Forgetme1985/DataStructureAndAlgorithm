#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
    node* previous;
};
class doublyLinkedList
{
    public:
    doublyLinkedList()
    {
        _listHead = NULL;
    }
    ~doublyLinkedList()
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
            _listHead->previous = travelNode;
        }
    }
    void addNode(int val)//add node on the right side
    {
        if(_listHead == NULL)
        {
            _listHead = new node;
            _listHead->value = val;
            _listHead->next = _listHead;
            _listHead->previous = _listHead;
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
           newNode->previous = travelNode;
           newNode->next = _listHead;
        }
    }
    void insertNode(int val,int k)
    {
        int count = 1;
        node* travelNode = _listHead;
        if(travelNode == NULL)
        {
            cout << "empty list!\n";
            return;
        }
        while(count < k)
        {
            count++;
            travelNode = travelNode->next;
        }
        node* newNode = new node;
        newNode->value = val;
        newNode->next = travelNode;
        travelNode->previous->next = newNode;
        newNode->previous = travelNode->previous;
        travelNode->previous = newNode;
    }
    

    private:
    node* _listHead;
};
int main()
{
    doublyLinkedList list;
    list.addNode(3);
    list.addNode(2);
    list.addNode(1);
    list.displayNodes();// 3 2 1
    list.removeNode();
    list.displayNodes();// 2 1
    list.insertNode(3,2);
    list.displayNodes();// 2 3 1
    return 0;
}