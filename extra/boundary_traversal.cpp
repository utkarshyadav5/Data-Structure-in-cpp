#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node* createNode(int value){
    Node* newNode = new Node(value);
    return newNode;
}

void printLeft(Node* root){
    if(root){
        if(root->left){
            cout<<root->data<<" ";
            printLeft(root->left);
        }
        else if(root->right){
            cout<<root->data<<" ";
            printLeft(root->right);
        }
    }
}

void printRight(Node* root){
    if(root){
        if(root->right){
            cout<<root->data<<" ";
            printRight(root->right);
        }
        else if(root->left){
            cout<<root->data<<" ";
            printRight(root->left);
        }
    }
}

void printLeaf(Node* root){
    if(root){
        printLeaf(root->left);

        if(root->left==NULL && root->right==NULL)
            cout<<root->data<<" ";

        printLeaf(root->right);
    }
}

void printBoundary(Node *root){
    if(root){
        cout<<root->data<<" ";
        printLeft(root->left);

        printLeaf(root->left);
        printLeaf(root->right);

        printRight(root->right);
    }
}

int main(){
    Node *root         = createNode(20);
    root->left                = createNode(8);
    root->left->left          = createNode(4);
    root->left->right         = createNode(12);
    root->left->right->left   = createNode(10);
    root->left->right->right  = createNode(14);
    root->right               = createNode(22);
    root->right->right        = createNode(25);

    printBoundary( root );
    cout<<endl;
    return 0;
}