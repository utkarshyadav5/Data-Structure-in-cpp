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

    int iterativeHeight(Node* root){
        if(root==NULL)
            return 0;

        queue<Node*> q;
        q.push(root);

        int height=0;

        while(1){
            int nodeCount=q.size();

            if(nodeCount==0)
                return height;

            height++;
            while(nodeCount>0){
                Node* temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                nodeCount--;
            }
        }
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

    void doubleTree(Node* root){
        if(root==NULL)
            return;

        doubleTree(root->left);
        doubleTree(root->right);
        Node* newNode=CreateNode(root->data);
        Node* temp=root->left;
        root->left=newNode;
        newNode->left=temp;
    }

    int maxWidth(Node* root){
        if(root==NULL)
            return 0;

        int result=0;

        queue<Node* > q;
        q.push(root);
        while(!q.empty()){

            int count=q.size();

            result=max(count,result);

            while(count--){
                Node* temp=q.front();
                q.pop();

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }

        }
        return result;
    }

    bool isFoldableUtil(Node* a,Node* b){
        if(a==NULL && b==NULL)
            return true;

        if(a==NULL || b==NULL)
            return false;

        return isFoldableUtil(a->left,b->right) &&
                    isFoldableUtil(a->right,b->left);
    }

    bool isFoldable(Node* root){
        if(root==NULL)
            return true;

        return isFoldableUtil(root->left,root->right);
    }

    void printKdist(Node* root,int k){
        int level=0;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int count=q.size();

            if(level==k){
                while(count--){
                    cout<<q.front()->data<<" ";
                    q.pop();
                }
                return;
            }
            level++;
            while(count--){
                Node* temp=q.front();
                q.pop();

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }

    void printKDist(Node* root,int k){
        if(root==NULL)
            return;

        if(k==0){
            cout<<root->data<<" ";
            return;
        }
        else{
            printKDist(root->left,k-1);
            printKDist(root->right,k-1);
        }
    }

    int level(Node* root,int key,int l){
        if(root==NULL)
            return 0;

        if(root->data==key){
            return l;
        }
        else{
            int lvl;
            lvl=level(root->left,key,l+1);
            if(lvl!=0)
                return lvl;
            lvl=level(root->right,key,l+1);
            return lvl;
        }
    }

    bool ancestors(Node* root,int key){
        if(root==NULL)
            return false;

        if(root->data==key)
            return true;

        if(ancestors(root->left,key) || ancestors(root->right,key)){
            cout<<root->data<<" ";
            return true;
        }

        return false;
    }

    bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL)
            return true;

        return false;
    }

    bool isSumTree(Node* root){
        int ls,rs;

        if(root==NULL || isLeaf(root))
            return true;

        if(isSumTree(root->left) && isSumTree(root->right)){

            if(root->left==NULL)
                ls=0;
            else if(isLeaf(root->left))
                ls=root->left->data;
            else
                ls=2*(root->left->data);

            if(root->right==NULL)
                ls=0;
            else if(isLeaf(root->right))
                ls=root->right->data;
            else
                ls=2*(root->right->data);

            return (ls+rs==root->data);

        }
        return false;
    }

    bool areIdentical(Node* t1,Node* t2){
        if(t1==NULL && t2==NULL)
            return true;

        if(t1==NULL || t2==NULL)
            return false;

        return ((t1->data==t2->data) && areIdentical(t1->left,t2->left)
            && areIdentical(t1->right,t2->right));
    }

    bool isSubTree(Node* t1,Node* t2){
        if(t2==NULL)
            return true;

        if(t1==NULL)
            return false;

        if(areIdentical(t1,t2))
            return true;

        return isSubTree(t1->left,t2)||isSubTree(t1->right,t2);
    }

    int toSumTree(Node* root){
        if(root==NULL)
            return 0;

        int old_val=root->data;

        root->data=toSumTree(root->left)+toSumTree(root->right);
        return old_val+root->data;
    }

    // unordered_map<int,int> myMap;

    // void verticalSum(Node* root,int dist){
    //     if(root==NULL)
    //         return;

    //     verticalSum(root->left,dist-1);

    //     if(myMap.find(dist)==myMap.end())
    //         myMap.insert(make_pair(dist,root->data));
    //     else
    //         myMap[dist]=myMap[dist]+root->data;

    //     verticalSum(root->right,dist+1);
    // }

    int maxSum(Node* root){

        if(root==NULL)
            return 0;

        int leftVal=maxSum(root->left);
        int rightVal=maxSum(root->right);

        return root->data+max(leftVal,rightVal);

    }

    Node* constructTreefrmpreOrder(int pre[],char preLN[],int *index_ptr,int n){
        int index=*index_ptr;

        if(index==n)
            return NULL;

        Node* temp=CreateNode(pre[index]);
        (*index_ptr)++;

        if(preLN[index]=='N'){
            temp->left=constructTreefrmpreOrder(pre,preLN,index_ptr,n);
            temp->right=constructTreefrmpreOrder(pre,preLN,index_ptr,n);
        }
        return temp;
    }

    bool checkComplete(Node* root){
        if(root==NULL)
            return true;

        queue<Node* > q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();

            if(temp->left){
                if(flag)
                    return false;
                q.push(temp->left);
            }
            else
                flag=true;

            if(temp->right){
                if(flag)
                    return false;
                q.push(temp->right);
            }
            else
                flag=true;
        }
        return true;
    }

    bool isComplete(Node* root,int index,int number_nodes){
        if(root==NULL)
            return true;

        if(index>=number_nodes)
            return false;

        return (isComplete(root->left,2*index+1,number_nodes) &&
            isComplete(root->right,2*index+2,number_nodes));
    }

    void iterativePre(Node* root){
        stack<Node*> s;
        s.push(root);

        while(!s.empty()){
            Node* top=s.top();
            s.pop();
            cout<<top->data<<" ";
            if(top->right)
                s.push(top->right);
            if(top->left)
                s.push(top->left);
        }
    }
    queue<Node*> q;
    void CompleteBT(Node** root,int data){
        Node* temp=CreateNode(data);

        if(!*root)
            *root=temp;
        else{
            Node* f=q.front();
            if(!f->left)
                f->left=temp;
            else if(!f->right)
                f->right=temp;

            if(f && f->left && f->right)
                q.pop();
        }
        q.push(temp);
    }

    int LSS(Node* root){
        if(root==NULL)
            return 0;

        // if(root->lss)
        //     return root->lss;

        // if(!root->left && !root->right)
        //     return (root->liss=1);

        int size_excl=LSS(root->left)+LSS(root->right);

        int size_incl=1;
        if(root->left)
            size_incl+=LSS(root->left->left)+LSS(root->left->right);
        if(root->right)
            size_incl+=LSS(root->right->left)+LSS(root->right->right);

        return max(size_excl,size_incl);
        // root->lss=max(size_excl,size_incl);

        // return root->liss;
    }

    void iterativePost1(Node* root){

        if(root==NULL)
            return;
        stack<Node*> s;

        do{
            while(root){
                if(root->right)
                    s.push(root->right);
                s.push(root);
                root=root->left;
            }

            root=s.top();
            s.pop();
            if(root->right && s.top()==root->right){
                s.pop();
                s.push(root);
                root=root->right;
            }
            else{
                cout<<root->data<<" ";
                root=NULL;
            }
        }while(!s.empty());
    }

    bool isIsomorphic(Node* root1,Node* root2){
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;

        if(root1->data==root2->data){
            return ((isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))
                || (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left)));
        }
        else
            return false;
    }

    int getDiff(Node* root){
        if(root==NULL)
            return 0;

        return root->data-(getDiff(root->left)+getDiff(root->right));
    }

    int oddDepth(Node* root,int level){
        int maxDepth;
        if(root==NULL)
            return 0;

        int left=oddDepth(root->left,level+1);
        int right=oddDepth(root->right,level+1);

        if(level%2)
            maxDepth=max(max(left,right),level);
        else
            maxDepth=max(left,right);

        return maxDepth;
    }

    bool checkLeaf(Node* root,int level,int *leaflevel){
        if(root==NULL)
            return true;

        if(!root->left && !root->right){
            if(*leaflevel==0){
                *leaflevel=level;
                return true;
            }
            else
                return (level==*leaflevel);
        }

        return checkLeaf(root->left,level+1,leaflevel) &&
                checkLeaf(root->right,level+1,leaflevel);
    }

    void leftView(Node* root,int level,int *maxLevel){
        if(root==NULL)
            return;

        if(level>(*maxLevel)){
            cout<<root->data<<" ";
            *maxLevel=level;
        }
        leftView(root->left,level+1,maxLevel);
        leftView(root->right,level+1,maxLevel);
    }

    void check(Node* root,int sum){
        if(root==NULL)
            return;

        check(root->left,sum+root->data);
        cout<<sum<<endl;
        check(root->right,sum+root->data);
    }

    // bool removeNodes(Node* root,int k){
    //     int sum;
    //     if(root==NULL)
    //         return true;

    //     sum=sum+root->data;
    //     if(isLeaf(root)){
    //         if(sum>=k)
    //             return true;
    //         else
    //             return false;
    //     }

    //     bool left=removeNodes(root->left,k);
    //     bool right=removeNodes(root->right,k);

    //     if(left==false){
    //         Node* temp=root->left;
    //         root->left=NULL;
    //         delete temp;
    //     }
    //     if(right==false){
    //         Node* temp=root->right;
    //         root->right=NULL;
    //         delete temp;
    //     }
    // }


int main(){
    Node* root=CreateNode(1);
    root->left=CreateNode(2);
    root->right=CreateNode(3);
    root->left->left=CreateNode(4);
    //root->left->right=CreateNode(5);
    root->right->right=CreateNode(6);
    //root->left->right->left=CreateNode(7);
    //root->left->right->right=CreateNode(8);

    Node* root2=CreateNode(1);
    root2->left=CreateNode(2);
    root2->right=CreateNode(3);
    root2->left->left=CreateNode(4);
    root2->left->right=CreateNode(5);
    root->left->left->right=CreateNode(8);
    root2->right->left=CreateNode(6);
    root2->right->right=CreateNode(7);
    //root2->right->right->left=CreateNode(3);
    //root2->right->right->right=CreateNode(9);

    // PreOrder(root);
    // cout<<endl;
    // InOrder(root);
    // cout<<endl;
    // PostOrder(root);
    // cout<<endl;
    // levelOrderPrint(root);
    //InOrderIterative(root);
    //cout<<endl;
    // MorrisTraversal(root);
    // cout<<endl;
    // cout<<size(root)<<endl;
    //cout<<identical(root,root2)<<endl;
    // cout<<height(root)<<endl;
    //cout<<height(root2)<<endl;
    // vector<int> v;
    // root2leaf(root,v);
    //printCircular(Tree2List(root));
    //cout<<childrenSum(root2)<<endl;
    // cout<<hasPathSum(root,100)<<endl;

    // int inOrder[6],preOrder[6];

    // for(int i=0;i<6;i++)
    //     cin>>preOrder[i];

    // for(int i=0;i<6;i++)
    //     cin>>inOrder[i];

    // Node* root3=buildTree(inOrder,preOrder,0,5);
    // InOrder(root3);
    // cout<<endl;
    //doubleTree(root);
    //levelOrderPrint(root);
    //cout<<maxWidth(root2)<<endl;
    //cout<<isFoldable(root2)<<endl;
    //printKDist(root2,2);
    //cout<<endl;
    //cout<<level(root,4,1)<<endl;
    // bool val=ancestors(root,5);
    // cout<<endl;
    // cout<<val<<endl;

    //cout<<maxSum(root2)<<endl;
    //cout<<checkComplete(root)<<endl;
    //cout<<checkComplete(root2)<<endl;
    //iterativePre(root);
    // cout<<endl;
    // Node* root3=NULL;
    // for(int i=1;i<12;i++)
    //     CompleteBT(&root3,i);
    // levelOrderPrint(root3);

    //cout<<LSS(root2)<<endl;
    //iterativePost1(root);
    //cout<<endl;
    // cout<<isIsomorphic(root,root2)<<endl;
    // cout<<getDiff(root)<<endl;

    // cout<<oddDepth(root,0)<<endl;

    // int leaflevel=0;
    // cout<<checkLeaf(root,0,&leaflevel)<<endl;

    int maxLevel=(-1);
    leftView(root2,0,&maxLevel);
    cout<<endl;
    int sum=0;
    check(root,sum);
    return 0;
}

















