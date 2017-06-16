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

    // struct Info{
    //     int size;
    //     int max;
    //     int min;
    //     int ans;
    //     bool isBST;
    // };

    // Info largestBST(Node* root){
    //     if(root==NULL)
    //         return {0,INT_MIN,INT_MAX,0,true};

    //     if(!root->left && !root->right)
    //         return{1,root->data,root->data,1,true};

    //     Info l=largestBST(root->left);
    //     Info r=largestBST(root->right);

    //     Info ret;
    //     ret.size=(1+l.size+r.size);

    //     if(l.isBST && r.isBST && l.max<root->data && r.min>root->data){
    //         ret.max=r.max;
    //         ret.min=l.min;
    //         ret.ans=ret.size;
    //         ret.isBST=true;

    //         return ret;
    //     }

    //     ret.ans=max(l.ans,r.ans);
    //     ret.isBST=false;

    //     return ret;
    // }
    //////////////////////////////////////////

    int sum=0;
    void addGreater(Node* root,int &sum){
        if(root==NULL)
            return;

        addGreater(root->right,sum);
        sum=sum+root->data;
        root->data=sum;
        addGreater(root->left,sum);
    }

    Node* removeOutside(Node* root,int min,int max){
        if(root==NULL)
            return NULL;

        root->left=removeOutside(root->left,min,max);
        root->right=removeOutside(root->right,min,max);

        if(root->data < min){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->data > max){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        return root;
    }

    bool hasOnlyOneChild(int pre[],int size){
        int min,max;
        if(pre[size-1]>pre[size-2]){
            max=pre[size-1];
            min=pre[size-2];
        }
        else{
            max=pre[size-2];
            min=pre[size-1];
        }

        for(int i=size-3;i>=0;i--){
            if(pre[i]<min)
                min=pre[i];
            else if(pre[i]>max)
                max=pre[i];
            else
                return false;
        }
        return true;
    }

    Node* pre=NULL;
    void convert2DLL(Node* root,Node* &head){
        if(root==NULL)
            return;

        convert2DLL(root->left,head);
        if(!pre)
            head=root;
        else{
            root->left=pre;
            pre->right=root;
        }
        pre=root;
        convert2DLL(root->right,head);
    }

    void findtail(Node* head,Node *&tail){
        Node* temp=head;

        while(temp)
            temp=temp->right;
        tail=temp;
    }

    bool isPresent(Node* head,Node* tail,int sum){
        while(head!=tail){
            int curr=head->data+tail->data;
            if(curr==sum)
                return true;
            else if(curr<sum)
                tail=tail->left;
            else
                head=head->right;
        }
        return false;
    }

    bool isTripletPresent(Node* root){
        if(root==NULL)
            return false;

        Node* head=NULL;
        convert2DLL(root,head);
        Node* tail=NULL;
        findtail(head,tail);

        while((head->right!=tail) && head->data<0){
            if(isPresent(head->right,tail,-1*head->data))
                return true;
            else
                head=head->right;
        }
        return false;
    }

    void swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }

    void swapNodes(Node* root,Node **first,Node **middle,Node **last,Node **pre){
        if(root){
            swapNodes(root->left,first,middle,last,pre);

            if((*pre) && (root->data < (*pre)->data)){
                if(!*first){
                    *first=*pre;
                    *middle=root;
                }
                else
                    *last=root;
            }
            *pre=root;
            swapNodes(root->right,first,middle,last,pre);
        }
    }

    void swapNodesUtil(Node* root){
        Node *first=NULL,*last=NULL,*middle=NULL,*pre=NULL;
        swapNodes(root,&first,&middle,&last,&pre);

        if(first && last)
            swap(&(first->data),&(last->data));
        else
            swap(&(first->data),&(middle->data));
    }

    int Ceil(Node* root,int key){
        if(root==NULL)
            return -1;

        if(root->data==key)
            return root->data;

        if(root->data < key)
            return Ceil(root->right,key);

        int ceil=Ceil(root->left,key);
        if(ceil>=key)
            return ceil;
        else
            return root->data;
    }

    Node* constructBST(int pre[],int size){
        stack <Node*> s;
        Node* root=CreateNode(pre[0]);
        s.push(root);

        Node* temp;
        for(int i=1;i<size;i++){
            temp=NULL;

            while(!s.empty() && pre[i]>(s.top())->data){
                temp=s.top();
                s.pop();
            }

            if(temp){
                temp->right=CreateNode(pre[i]);
                s.push(temp->right);
            }
            else{
                (s.top())->left=CreateNode(pre[i]);
                s.push((s.top())->left);
            }
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

    // cout<<(largestBST(root)).ans<<endl;
    // int sum=0;
    // addGreater(root,sum);
    // inOrder(root);
    // cout<<endl;

    // root=removeOutside(root,10,40);
    // inOrder(root);
    // cout<<endl;

    // cout<<isTripletPresent(root)<<endl;

    // Node *root3 = CreateNode(6);
    // root3->left        = CreateNode(10);
    // root3->right       = CreateNode(2);
    // root3->left->left  = CreateNode(1);
    // root3->left->right = CreateNode(3);
    // root3->right->right = CreateNode(12);
    // root3->right->left = CreateNode(7);
    // swapNodesUtil(root3);
    // inOrder(root3);
    // cout<<endl;

    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    Node* root3=constructBST(pre,size);
    inOrder(root3);
    cout<<endl;
    return 0;
}

























