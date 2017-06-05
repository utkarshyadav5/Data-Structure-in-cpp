#include <bits/stdc++.h>

using namespace std;

class Node{
public:

    int data;
    Node* left;
    Node* right;

    Node():data(0),left(NULL),right(NULL){}
    Node(int key):data(key),left(NULL),right(NULL){}
};

    Node* CreateNode(int data){
        Node* newNode=new Node(data);
        return newNode;
    }

    void PreOrder(Node* root){
        if(root==NULL)
            return;

        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void InOrder(Node* root){
        if(root==NULL)
            return;

        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }

    void PostOrder(Node* root){
        if(root==NULL)
            return;

        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }

    void levelOrderPrint(Node* root){
        queue< Node* > q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* front=q.front();
            if(q.front()==NULL){
                cout<<endl;
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                q.pop();
                cout<<front->data<<" ";
                if(front->left!=NULL)
                    q.push(front->left);
                if(front->right!=NULL)
                    q.push(front->right);
            }
        }
    }




int main(){
    Node* root=CreateNode(1);
    root->left=CreateNode(2);
    root->right=CreateNode(3);
    root->left->left=CreateNode(4);
    root->left->right=CreateNode(5);
    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    levelOrderPrint(root);

    return 0;
}

















