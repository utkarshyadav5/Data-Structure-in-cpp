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

    void kSmallest(Node* root,int &l,int k){
        if(root==NULL)
            return;

        kSmallest(root->left,l,k);
        if(l==k)
            cout<<root->data<<endl;
        l++;
        kSmallest(root->right,l,k);
    }

    int kSmallestusingMorris(Node* root,int k){
        int count=0;
        int ksmall=INT_MIN;

        Node *curr,*pre;
        curr=root;

        while(curr){

            if(curr->left==NULL){
                count++;
                if(count==k)
                    ksmall=curr->data;
                curr=curr->right;
            }

            else{

                pre=curr->left;
                while(pre->right!=NULL && pre->right!=curr)
                    pre=pre->right;
                if(pre->right==NULL){
                    pre->right=curr;
                    curr=curr->left;
                }
                else{
                    pre->right=NULL;
                    count++;
                    if(count==k)
                        ksmall=curr->data;
                    curr=curr->right;
                }
            }
        }
        return ksmall;
    }

    Node* array2BST(int arr[],int start,int end){
        if(start>end)
            return NULL;

        int mid=(start+end)/2;
        Node* root=CreateNode(arr[mid]);
        root->left=array2BST(arr,start,mid-1);
        root->right=array2BST(arr,mid+1,end);
        return root;
    }


    //////// ------ IMPORTANT ------ /////////

    struct Info{
        int size;
        int max;
        int min;
        int ans;
        bool isBST;
    };

    Info largestBST(Node* root){
        if(root==NULL)
            return {0,INT_MIN,INT_MAX,0,true};

        if(!root->left && !root->right)
            return{1,root->data,root->data,1,true};

        Info l=largestBST(root->left);
        Info r=largestBST(root->right);

        Info ret;
        ret.size=(1+l.size+r.size);

        if(l.isBST && r.isBST && l.max<root->data && r.min>root->data){
            ret.max=r.max;
            ret.min=l.min;
            ret.ans=ret.size;
            ret.isBST=true;

            return ret;
        }

        ret.ans=max(l.ans,r.ans);
        ret.isBST=false;

        return ret;
    }
    //////////////////////////////////////////

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

    // cout<<isBST(root)<<endl;

    // Node* temp=lca(root,20,80);
    // cout<<temp->data<<endl;

    // temp=lca_iterative(root,20,80);
    // cout<<temp->data<<endl;

    // Node* n=root->left->right;
    // temp=inorderSuccessor(root,n);
    // cout<<temp->data<<endl;

    int l=1;
    kSmallest(root,l,6);
    cout<<kSmallestusingMorris(root,6)<<endl;

    cout<<(largestBST(root)).ans<<endl;
    return 0;
}

























