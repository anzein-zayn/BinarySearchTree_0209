#include <iostream>
using namespace std;

class Node{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    Node()
    {
        leftchild = nullptr;
        rightchild = nullptr;
    }
};

class BinaryTree
{
public:
    Node *ROOT;
    BinaryTree()
    {
        ROOT = nullptr;
    }

    void insert()
    {
        int x;
        cout << " Masukkan nilai : ";
        cin >> x;
    Node *newNode = new Node();//1. Alokasi memory ke node baru
    newNode->info = x;//2. Assign value ke data field new node

    //3. Membuat kiri dan kanan child dari newNode menjadi NULL
    newNode ->leftchild = nullptr;
    newNode->rightchild = nullptr;

    Node *parent = nullptr;
    Node *currentNode = nullptr;
   
     search(x, parent, currentNode);

    if (parent==nullptr)
    {
        ROOT = newNode;//5. Menandai newNode seperti ROOT

        return;
    }

    if (x< parent-> info)//jika x lebih kecil dari parent
    {
        parent->leftchild = newNode;// maka buat leftchild parent ke newNode

        return;
    }

    if (x>parent->info)//jika x lebih besar dari parent
    {
        parent->rightchild = newNode;//maka buat rightchild dari parent menjadi point new node

        return;
    }
    }

    void search( int element, Node *&parent, Node*&currentNode)
    {
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && ( currentNode -> info != element))
        {
            parent = currentNode;
            if(element < currentNode->info)
                currentNode = currentNode ->leftchild;
            else    
                currentNode = currentNode->rightchild;
        }
    }
    
    void inorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << " Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        inorder(ptr->leftchild);
        cout << ptr->info << " ";
        inorder(ptr->rightchild);
    }

    void preorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << " Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        cout << ptr->info << " ";
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }

    void postorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << " Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
        cout << ptr->info << " ";
    }

    bool isEmpty()
    {
        return ROOT == nullptr;
    }
    
};

int main()
{
BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}
