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

    void InOrderIterative(Node* root){
        stack<Node*> s;
        Node* current=root;

        while(1){

            while(current!=NULL){
                s.push(current);
                current=current->left;
            }
            if(!s.empty() && current==NULL){
                Node* top=s.top();
                s.pop();
                cout<<top->data<<" ";
                current=top->right;
            }
            else
                break;
        }
    }

    void MorrisTraversal(Node* root){
        Node *current, *pre;

        current=root;
        while(current){
            if(current->left==NULL){
                cout<<current->data<<" ";
                current=current->right;
            }
            else{
                //find inorder predecessor of current
                pre=current->left;
                while(pre->right!=NULL && pre->right!=current)
                    pre=pre->right;

                if(pre->right==NULL){
                    pre->right=current;
                    current=current->left;
                }

                else{
                    pre->right=NULL;
                    cout<<current->data<<" ";
                    current=current->right;
                }
            }
        }
    }

    int size(Node* n){
        if(n==NULL)
            return 0;

        return 1+size(n->left)+size(n->right);
    }

    bool identical(Node* root1,Node* root2){
        if(root1==NULL && root2==NULL)
            return true;

        else if(root1!=NULL && root2!=NULL)
            return (root1->data==root2->data && identical(root1->left,root2->left) && identical(root1->right,root2->right));
        else
            return false;
    }

    int height(Node* root){
        if(root==NULL)
            return 0;

        return 1+max(height(root->left),height(root->right));
    }

    void mirror(Node* root){
        if(root==NULL)
            return;

        mirror(root->left);
        mirror(root->right);
        if(root->left || root->right){
            Node*temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
    }

    vector<int>::iterator it;

    void printArray(vector<int> v){
        for(it=v.begin();it!=v.end();it++)
            cout<<(*it)<<" ";
        cout<<endl;
    }

    void root2leaf(Node* root,vector<int> v){
        if(root!=NULL)
            v.push_back(root->data);

        if(root->left==NULL && root->right==NULL)
            printArray(v);
        else{
            root2leaf(root->left,v);
            root2leaf(root->right,v);
        }
    }

    Node* concatenate(Node* leftList,Node* rightList){
        if(leftList==NULL)
            return rightList;
        if(rightList==NULL)
            return leftList;

        Node* leftLast=leftList->left;
        Node* rightLast=rightList->left;

        leftLast->right=rightList;
        rightList->left=leftLast;
        leftList->left=rightLast;
        rightLast->right=leftList;

        return leftList;
    }

    Node* Tree2List(Node* root){
        if(root==NULL)
            return NULL;

        Node* left=Tree2List(root->left);
        Node* right=Tree2List(root->right);

        root->left=root->right=root;

        return concatenate(concatenate(left,root),right);
    }

    void printCircular(Node* root){
        Node* temp=root;
        do{
            cout<<temp->data<<" ";
            temp=temp->right;
        }while(temp!=root);
        cout<<endl;
    }

    bool childrenSum(Node* root){
        int left_data=0,right_data=0;

        if(root==NULL || (root->left==NULL && root->right==NULL))
            return true;
        else{
            if(root->left!=NULL)
                left_data=root->left->data;

            if(root->right!=NULL)
                right_data=root->right->data;

            if((root->data==left_data+right_data) &&
                childrenSum(root->left) && childrenSum(root->right))
                return true;
            else
                return false;
        }
    }

    int diameter(Node* root){
        if(root==NULL)
            return 0;

        int option1=diameter(root->left);
        int option2=diameter(root->right);
        int option3=1+height(root->left)+height(root->right);

        return max(max(option1,option2),option3);
    }

    bool isBalanced(Node* root){
        if(root==NULL)
            return true;

        int left=height(root->left);
        int right=height(root->right);

        if(abs(left-right)<=1 && isBalanced(root->left)
            && isBalanced(root->right))
            return true;

        return false;
    }

    bool hasPathSum(Node* root,int sum){
        if(root==NULL)
            return (sum==0);

        return (hasPathSum(root->left,sum-root->data)
            || hasPathSum(root->right,sum-root->data));
    }

    int find(int inOrder[],int data){
        int val=0;
        for(int i=0;i<6;i++)
            if(data==inOrder[i])
                val=i;
        return val;
    }

    int current=0;

    Node* buildTree(int inOrder[],int preOrder[],int inStart,int inEnd){
        if(inStart>inEnd)
            return NULL;

        Node* root=CreateNode(preOrder[current]);
        current++;
        if(inStart==inEnd)
            return root;

        int inIndex=find(inOrder,root->data);

        root->left=buildTree(inOrder,preOrder,inStart,inIndex-1);
        root->right=buildTree(inOrder,preOrder,inIndex+1,inEnd);

        return root;
    }


int main(){
    Node* root=CreateNode(1);
    root->left=CreateNode(2);
    root->right=CreateNode(3);
    root->left->left=CreateNode(4);
    root->left->right=CreateNode(5);

    Node* root2=CreateNode(10);
    root2->left=CreateNode(8);
    root2->right=CreateNode(2);
    root2->left->left=CreateNode(3);
    root2->left->right=CreateNode(5);
    root2->right->left=CreateNode(2);

    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    levelOrderPrint(root);
    //InOrderIterative(root);
    //cout<<endl;
    MorrisTraversal(root);
    cout<<endl;
    cout<<size(root)<<endl;
    cout<<identical(root,root2)<<endl;
    cout<<height(root)<<endl;
    cout<<height(root2)<<endl;
    vector<int> v;
    root2leaf(root,v);
    //printCircular(Tree2List(root));
    cout<<childrenSum(root2)<<endl;
    cout<<hasPathSum(root,100)<<endl;

    int inOrder[6],preOrder[6];

    for(int i=0;i<6;i++)
        cin>>preOrder[i];

    for(int i=0;i<6;i++)
        cin>>inOrder[i];

    Node* root3=buildTree(inOrder,preOrder,0,5);
    InOrder(root3);
    cout<<endl;
    return 0;
}

















