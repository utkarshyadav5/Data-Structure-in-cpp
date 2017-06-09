#include <bits/stdc++.h>

using namespace std;

string alphabet[] = {"", "a", "b", "c", "d", "e",
        "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
        "s", "t", "u", "v", "w", "x", "v", "z"};

class Node{
public:
    string s;
    Node *left,*right;
    Node():s(""),left(NULL),right(NULL){}
    Node(string data):s(data),left(NULL),right(NULL){}
};

Node* CreateNode(){
    Node* temp=new Node();
    return temp;
}

Node* CreateNode(string data){
    Node* temp=new Node(data);
    return temp;
}

void BuildTree(Node* root,int arr[],int start,int size){
    if(start==size)
        return;

    string temp=root->s;
    string newStr=(root->s).append(alphabet[arr[start]]);
    root->s=temp;

    root->left=CreateNode(newStr);
    BuildTree(root->left,arr,start+1,size);

    if(start<size-1){
        int n=((10*arr[start])+arr[start+1]);
        if(n<26){

            temp=root->s;
            newStr=(root->s).append(alphabet[n]);
            root->s=temp;

            root->right=CreateNode(newStr);
            BuildTree(root->right,arr,start+2,size);
        }
    }
}

void print(Node* root){
    if(root==NULL)
        return;

    if(!root->left && !root->right)
        cout<<root->s<<endl;

    print(root->left);
    print(root->right);
}

int main(){
    Node* root;
    root=CreateNode();
    int arr[]={1,2,2,1};

    BuildTree(root,arr,0,4);
    print(root);

    return 0;
}












