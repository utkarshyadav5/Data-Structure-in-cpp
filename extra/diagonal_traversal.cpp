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
    Node *newNode = new Node(value);
    return newNode;
}

map<int,vector<int> > myMap;

void diagonalPrintUtil(Node* root,int level){
    if(root==NULL)
        return;

    myMap[level].push_back(root->data);
    diagonalPrintUtil(root->left,level+1);
    diagonalPrintUtil(root->right,level);
}

void diagonalPrint(Node *root){
    diagonalPrintUtil(root,0);

    map<int,vector<int> >::iterator it;

    for(it=myMap.begin();it!=myMap.end();it++){
        int j=(*it).first;
        for(int i=0;i<myMap[j].size();i++)
            cout<<myMap[j][i]<<" ";
        cout<<endl;
    }
}

int main(){
    Node* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);

    diagonalPrint(root);
    return 0;
}