#include <iostream>
using namespace std;

struct node
{
    char data;
    node* leftChild;
    node* rightChild;
};
class binaryTree
{
    public:
    binaryTree(char c)
    {
        _root = new node;
        _root->data = c;
        _root->leftChild = NULL;
        _root->rightChild = NULL;
    }
    ~binaryTree()
    {
        delete _root;
    }
    void addLeft(node* n,char c)
    {
        n->leftChild = new node;
        n->leftChild->data = c;
        n->leftChild->leftChild = NULL;
        n->leftChild->rightChild = NULL;
    }
    void addRight(node* n, char c)
    {
        n->rightChild = new node;
        n->rightChild->data = c;
        n->rightChild->leftChild = NULL;
        n->rightChild->rightChild = NULL;
    }
    void lprTravelsal(node* node)//inorder travelsal
    {
        if(node != NULL)
        {
            lrpTravelsal(node->leftChild);
            cout << node->data << " ";
            lrpTravelsal(node->rightChild);
        }
    }
    void lrpTravelsal(node* node)//postorder travelsal
    {
        if(node != NULL)
        {
            lrpTravelsal(node->leftChild);
            lrpTravelsal(node->rightChild);
            cout << node->data << " ";
        }
    }
    void plrTravelsal(node* node)//preorder travelsal
    {
         if(node != NULL)
        {
            cout << node->data << " ";
            plrTravelsal(node->leftChild);
            plrTravelsal(node->rightChild);
        }
    }
    node* getRoot()
    {
        return _root;
    }
    private:
    node* _root;
};
int main()
{
    binaryTree tree('P');
    node* temp = tree.getRoot();
    tree.addLeft(temp,'Q');//add the left child of root
    tree.addRight(temp,'R');// add the right child of root
    //left branch
    node* tempLeft = temp->leftChild;
    tree.addLeft(tempLeft,'S');
    tempLeft = tempLeft->leftChild;
    tree.addRight(tempLeft,'T');
    //right branch
    node* tempRight = temp->rightChild;
    tree.addLeft(tempRight,'U');
    tree.addRight(tempRight,'V');
    tempRight = tempRight->leftChild;
    tree.addLeft(tempRight,'W');

    tree.lprTravelsal(tree.getRoot());
    cout << endl;
    tree.lrpTravelsal(tree.getRoot());
    cout << endl;
    tree.plrTravelsal(tree.getRoot());
    cout << endl;
    return 0;
}