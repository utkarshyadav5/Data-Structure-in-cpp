#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *left,*right;

    Node():data(0),left(NULL),right(NULL){}
    Node(int key):data(key),left(NULL),right(NULL){}
};

Node* CreateNode(){
    Node* newNode=new Node();
    return newNode;
}

Node* CreateNode(int data){
    Node* newNode=new Node(data);
    return newNode;
}

Node* search(Node* root,int key){
    if(root==NULL)
        return NULL;

    if(root->data==key)
        return root;
    else if(root->data>key)
        return search(root->left,key);
    else
        return search(root->right,key);
}

Node* insert(Node* root,int key){
    if(root==NULL){
        root=CreateNode(key);
        return root;
    }
    if(key < root->data)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);

    return root;
}

void inOrder(Node* root){
    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node* getMin(Node* root){
    Node* temp=root;

    while(temp->left)
        temp=temp->left;

    return temp;
}

Node* deleteNode(Node* root,int key){
    if(root==NULL)
        return root;

    if(key < root->data)
        root->left=deleteNode(root->left,key);
    else if(key > root->data)
        root->right=deleteNode(root->right,key);
    else{
        if(!root->left){
            Node* temp=root->right;
            delete(root);
            return temp;
        }
        else if(!root->right){
            Node* temp=root->left;
            delete(root);
            return temp;
        }
        //find inorder successor
        Node* temp=getMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

int main(){
    Node* root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    inOrder(root);
    cout<<endl;
    // Node* found=search(root,40);
    // if(found)
    //     cout<<found->data<<endl;
    // else
    //     cout<<"Not found"<<endl;

    root=deleteNode(root,50);
    inOrder(root);
    cout<<endl;

    return 0;
}

























