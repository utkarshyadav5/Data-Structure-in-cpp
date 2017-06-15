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
    Node* prev=NULL;
    bool isBST(Node* root){
        if(root){
            if(!isBST(root->left))
                return false;

            if(prev && root->data <= prev->data)
                return false;

            prev=root;
            return isBST(root->right);
        }
        return true;
    }

    Node* lca(Node* root,int n1,int n2){
        if(root==NULL)
            return NULL;

        if(n1 < root->data && n2 < root->data)
            return lca(root->left,n1,n2);
        if(n1 > root->data && n2 > root->data)
            return lca(root->right,n1,n2);

        return root;
    }

    Node* lca_iterative(Node* root,int n1,int n2){
        while(root){
            if(n1 < root->data && n2 < root->data)
                root=root->left;
            else if(n1 > root->data && n2 > root->data)
                root=root->right;
            else
                break;
        }
        return root;
    }

    Node* inorderSuccessor(Node* root,Node* n){
        if(n->right)
            return getMin(root->right);

        Node* succ=NULL;
        while(root){
            if(n->data < root->data){
                succ=root;
                root=root->left;
            }
            else if(n->data > root->data)
                root=root->right;
            else
                break;
        }
        return succ;
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

    // root=deleteNode(root,50);
    // inOrder(root);
    // cout<<endl;

    cout<<isBST(root)<<endl;

    Node* temp=lca(root,20,80);
    cout<<temp->data<<endl;

    temp=lca_iterative(root,20,80);
    cout<<temp->data<<endl;

    Node* n=root->left->right;
    temp=inorderSuccessor(root,n);
    cout<<temp->data<<endl;

    return 0;
}

























