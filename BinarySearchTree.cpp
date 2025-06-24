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

    

};