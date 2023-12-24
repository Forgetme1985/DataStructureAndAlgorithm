#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
};
class singlyLinkedList
{
    public:
    singlyLinkedList()
    {
        _listHead = NULL;
    }
    ~singlyLinkedList()
    {
        while(_listHead != NULL)
        {
            node* temp = _listHead;
            _listHead = _listHead->next;
            delete temp;
        }
    }
    void displayNodes()
    {
        node* temp =_listHead;
        while(temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
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
    void removeLastNode()//remove the node on the left side
    {
        if(_listHead == NULL)
        {
            cout << "the list is empty\n";
            return;
        }
        else{
            node* travelNode = _listHead;
            node* previousNode = _listHead;
            while(travelNode->next != NULL)
            {
                previousNode = travelNode;
                travelNode = travelNode->next;
            }
            previousNode->next = NULL;
            delete travelNode;
        }
    }
    void addNode(int val)//add node on the right side
    {
        if(_listHead == NULL)
        {
            _listHead = new node;
            _listHead->value = val;
            _listHead->next = NULL;
        }
        else{
            node* newNode = new node;
            newNode->value = val;
            newNode->next = _listHead;
            _listHead = newNode;
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
    void merge(singlyLinkedList& list2)
    {
        node* temp = _listHead;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        node* temp2 = list2._listHead;
        while(temp2 != NULL)
        {
            node* newNode = new node;
            newNode->value = temp2->value;
            newNode->next = NULL;
            temp->next = newNode;
            temp = newNode;
            temp2 = temp2->next;
        }
    }

    private:
    node* _listHead;
};
int main()
{
    singlyLinkedList list;
    list.addNode(4);
    list.addNode(2);
    list.addNode(1);
    list.displayNodes();// 1 2 4
    list.insertNode(3,3);
    list.displayNodes();// 1 2 3 4
    list.removeLastNode();
    list.displayNodes();// 1 2 3

    singlyLinkedList list2;
    list2.addNode(6);
    list2.addNode(5);
    list.merge(list2);
    list.displayNodes();//1 2 3 5 6
    return 0;
}