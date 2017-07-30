#include <bits/stdc++.h>

using namespace std;

class LinkedList;

class Node{
    int data;
    Node* next;
    bool visited;
public:
    Node(): data(0),next(NULL),visited(false){}
    Node(int value): data(value),next(NULL),visited(false){}
    friend class LinkedList;
    friend Node* merge(Node* ,Node*);
    friend void Insert(int d1,int d2);
    friend void get_intersection(Node* a, Node* b);
    friend int recursive_len(Node* t1);
    friend Node* intersection(Node* t1,Node* t2);
    friend Node* mergeSort(Node* t1);
    friend void FrontBackSplit(Node* t1,Node** a,Node** b);
    friend Node* mergeAlt(Node* t1,Node* t2,int val);
    friend Node* quickSort_helper(Node* t1);
    friend Node* quickSort(Node* t1,Node* end);
    friend Node* partition(Node* t1,Node** newHead,Node** newEnd);
};

class LinkedList{
public:
    Node* head;
    LinkedList(): head(NULL){}

    void print(){
       Node* temp=head;
       while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
       }
       cout<<endl;
    }

    void InsertAtFront(int d){
        if(head==NULL)
            head=new Node(d);
        else{
            Node* temp=head;
            head=new Node(d);
            head->next=temp;
        }
    }

    void InsertAtMiddle(int d,int at_index){
        if(head==NULL)
            head=new Node(d);
        else{
            Node* temp=head;
            at_index--;
            while(temp->next!=NULL && at_index){
                temp=temp->next;
                at_index--;
            }
            Node* newNode=new Node(d);
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }

    void InsertAtEnd(int d){
        if(head==NULL)
            head=new Node(d);
        else{
            Node* temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            Node* newNode=new Node(d);
            temp->next=newNode;
        }
    }

    void deleteNode(int value){
        Node* temp=head;
        Node* prev;
        if(temp->data==value){                      //found at head
            head=temp->next;
            delete temp;
            return;
        }
        else{
            while(temp!=NULL && temp->data!=value){
                prev=temp;
                temp=temp->next;
            }
            if(temp==NULL)
                return;
            prev->next=temp->next;
            delete(temp);
        }
    }

    int length(){                                 //iterative
        Node* temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }

    int recursive_length(Node* head){
        if(head==NULL)
            return 0;

        return 1+recursive_length(head->next);
    }

    void length_helper(){
        cout<<recursive_length(head)<<endl;
    }

    void swapNode(int x1,int x2){
        Node* prevX=NULL;
        Node* currX=head;
        Node* prevY=NULL;
        Node* currY=head;

        while(currX && currX->data!=x1){
            prevX=currX;
            currX=currX->next;
        }

        while(currY && currY->data!=x2){
            prevY=currY;
            currY=currY->next;
        }

        if(prevX)
            prevX->next=currY;
        else
            head=currY;

        if(prevY)
            prevY->next=currX;
        else
            head=currX;

        Node*temp=currX->next;
        currX->next=currY->next;
        currY->next=temp;
    }

    void getNth(int n){
        if(recursive_length(head)<n)
            return;
        Node* temp=head;
        while(temp && n){
            temp=temp->next;
            n--;
        }
        cout<<"The node is "<<temp->data<<endl;
    }

    void middle(){
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        cout<<"Middle : "<<slow->data<<endl;
    }

    void nthFromEnd(int n){
        Node* main_ptr=head;
        Node* ref_ptr=head;

        while(n--)
            ref_ptr=ref_ptr->next;

        while(ref_ptr){
            main_ptr=main_ptr->next;
            ref_ptr=ref_ptr->next;
        }
        cout<<"Nth from end is "<<main_ptr->data<<endl;
    }

    void reverse(){
        Node* prev=NULL;
        Node* curr=head;
        Node* nxt;

        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head=prev;
    }

    void recursive_reverse(Node** head){
        if(*head==NULL)
            return;

        Node* first=*head;
        Node* rest=first->next;

        if(rest==NULL)
            return;

        recursive_reverse(&rest);
        first->next->next=first;

        first->next=NULL;

        *head=rest;
    }

    void reverse_helper(){
        recursive_reverse(&head);
    }

    void loop_maker(){                          //fxn for making loop
        Node* temp=head;
        Node* newtemp;
        newtemp=temp->next->next;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newtemp;
    }

    void loop(){
        Node* temp=head;

        while(temp && temp->visited!=true){
            temp->visited=true;
            temp=temp->next;
            if(temp && temp->visited==true){
                cout<<"Loop found"<<endl;
                return;
            }
        }
        cout<<"Loop Not found"<<endl;
    }

    void deleteUnknown(Node* unknown){
        Node* temp=unknown->next;
        unknown=temp;
        delete(temp);
    }

    void print_reverse(Node* head){
        if(head==NULL)
            return;

        print_reverse(head->next);
        cout<<head->data<<" -> ";
    }

    void print_reverse_helper(){
        print_reverse(head);
    }

    void remove_duplicates(){
        Node* temp=head;
        while(temp->next){
            if(temp->data==temp->next->data){
                Node* newNode=temp->next;
                temp->next=newNode->next;
                delete(newNode);
            }
            else
                temp=temp->next;
        }
    }

    void pairwise_swap(){
        Node* temp=head;
        while(temp && temp->next){
            swap(temp->data,temp->next->data);
            temp=temp->next->next;
        }
    }

    void lastTofirst(){
        Node* temp=head;
        Node* prev;
        while(temp->next){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        temp->next=head;
        head=temp;
    }

    Node* alternateDelete(){
        Node* newNode=head;
        Node* temp;
        while(newNode && newNode->next){
            temp=newNode->next;
            newNode->next=temp->next;
            delete(temp);
            newNode=newNode->next;
        }
    }

    void alternate_split(){
        Node* a=head;
        Node* b=head->next;

        Node* head_a=a;
        Node* head_b=b;

        while(a && b){
            a->next=b->next;
            if(a->next)
                b->next=a->next->next;
            else{
                b->next=NULL;
                break;
            }
            a=a->next;
            b=b->next;
        }


        while(head_a){
            cout<<head_a->data<<" -> ";
            head_a=head_a->next;
        }
        cout<<endl;
        while(head_b){
            cout<<head_b->data<<" -> ";
            head_b=head_b->next;
        }
        cout<<endl;
    }

    Node* kReverse(Node* head,int k){
        Node* current=head;
        Node* prev=NULL;
        Node* next;
        int count=0;

        while(current && count<k){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            count++;
        }

        if(current)
            head->next=kReverse(current,k);

        return prev;
    }

    Node* kAltReverse(Node* head,int k){
        Node* current=head;
        Node* prev=NULL;
        Node* nxt;
        int count=0;

        while(current && count<k){
            nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt;
            count++;
        }
        if(head)
            head->next=current;

        count=0;
        while(count<(k-1) && current){
            current=current->next;
            count++;
        }

        if(current)
            current->next=kReverse(current->next,k);

        return prev;
    }

    void DeleteSmaller(){
        reverse();
        Node* temp=head;
        int maxm=head->data;
        while(temp->next){
            if(temp->next->data < temp->data){
                Node* newNode=temp->next;
                temp->next=newNode->next;
                delete(newNode);
            }
            else{
                temp=temp->next;
                maxm=temp->data;
            }
        }
        reverse();
    }

    void Segregate(){
        Node* temp=head;
        Node* even;
        Node* odd;
        Node* odd_head;

        bool even_v=false,odd_v=false;

        while(temp){
            if(temp->data%2==0){
                if(!even_v){
                    even_v=true;
                    head=temp;
                    even=temp;
                }
                else{
                    even->next=temp;
                    even=even->next;
                }
            }
            else{
                if(!odd_v){
                    odd_v=true;
                    odd_head=temp;
                    odd=temp;
                }
                else{
                    odd->next=temp;
                    odd=odd->next;
                }
            }
            temp=temp->next;
        }
        odd->next=NULL;
        if(even)
            even->next=odd_head;
        else
            head=odd_head;
    }

    void detectAndRemoveLoop(){
        Node* slow=head;
        Node* fast=head;

        while(fast && fast->next){
            if(slow==fast)
                break;
            slow=slow->next;
            fast=fast->next->next;
        }

        if(slow==fast){
            slow=head;
            while(slow != fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
    }

    void rotate(int k){
        Node* temp=head;
        Node* newNode;
        Node* tail;

        while(temp->next)
            temp=temp->next;

        tail=temp;

        while(k){
            temp=head;
            newNode=temp;
            head=temp->next;
            tail->next=newNode;
            newNode->next=NULL;
            tail=tail->next;
            k--;
        }
    }

    Node* add(Node* t1,Node* t2,int carry){
        Node* result;
        int a,b,sum;
        if(t1==NULL && t2==NULL && carry==0)
            return NULL;
        else if(t1==NULL && t2==NULL && carry){
            a=0;
            b=0;
        }
        else if(t1==NULL && t2){
            a=0;
            b=t2->data;
        }
        else if(t1 && t2==NULL){
            a=t1->data;
            b=0;
        }
        else{
            a=t1->data;
            b=t2->data;
        }
        sum=a+b+carry;
        if(sum>9){
            sum=sum%10;
            carry=1;
        }
        else{
            carry=0;
        }

        result=new Node(sum);
        if(t1->next && t2->next)
            result->next=add(t1->next,t2->next,carry);
        else if(t1->next && t2->next==NULL)
            result->next=add(t1->next,t2,carry);
        else if(t2->next && t1->next==NULL)
            result->next=add(t1,t2->next,carry);
        return result;
    }

    Node* add_helper(Node* t1,Node* t2){
        recursive_reverse(&t1);
        recursive_reverse(&t2);
        Node* sum;
        sum=add(t1,t2,0);
        recursive_reverse(&sum);
        return sum;
    }

    Node* deleteMN(int m,int n){
        Node* temp=head;
        Node* prev;
        Node* newNode;
        while(temp){
            int count=0;
            while(temp && count<m){
                prev=temp;
                temp=temp->next;
                count++;
            }
            count=0;
            while(temp && count<n){
                newNode=temp;
                temp=temp->next;
                prev->next=temp;
                delete(newNode);
                count++;
            }
        }
    }

    Node* insertionSort(){
        Node* temp=head;
        Node* tmp;
        Node* newHead=NULL;
        while(temp){
            if(newHead==NULL){
                newHead=temp;
                newHead->next=NULL;
                temp=temp->next;
            }
            else{
                if(newHead->data > temp->data){
                    tmp=newHead;
                    newHead=temp;
                    temp=temp->next;
                    newHead->next=tmp;
                }
                else{
                    Node* new_temp=newHead;
                    while(new_temp->next && new_temp->next->data < temp->data)
                        new_temp=new_temp->next;
                    tmp=new_temp->next;
                    new_temp->next=temp;
                    new_temp=new_temp->next;
                    temp=temp->next;
                    new_temp->next=tmp;
                }
            }
        }
        return newHead;
    }

};

LinkedList l1,l2,l3;

    void Insert(int data1,int data2){
        Node* newNode1=new Node(data1);
        Node* newNode2=new Node(data2);
        l1.head=newNode1;
        newNode1->next=newNode2;

        Node* temp=l2.head;
        temp->next=newNode1;
    }

    int recursive_len(Node* t1){
        if(t1==NULL)
            return 0;

        return 1+recursive_len(t1->next);
    }

    void get_intersection(Node* t1,Node* t2){
        int len1=recursive_len(t1);
        int len2=recursive_len(t2);

        int diff=len1-len2;

        if(diff>0){
            while(diff){
                t1=t1->next;
                diff--;
            }
        }
        else{
            diff=abs(diff);
            while(diff){
                t2=t2->next;
                diff--;
            }
        }
        while(t1->data!=t2->data){
            t1=t1->next;
            t2=t2->next;
        }
        cout<<t1->data<<endl;
    }

    Node* merge(Node *t1,Node *t2){
        Node* result=NULL;
        if(t1==NULL)
            return t2;
        if(t2==NULL)
            return t1;

        if(t1->data<=t2->data){
            result=t1;
            result->next=merge(t1->next,t2);
        }
        else{
            result=t2;
            result->next=merge(t1,t2->next);
        }
        return result;
    }

    Node* intersection(Node* t1,Node* t2){
        Node* result;
        if(t1==NULL || t2==NULL)
            return NULL;

        if(t1->data==t2->data){
            result=t1;
            result->next=intersection(t1->next,t2->next);
        }
        else if(t1->data<t2->data){
            return intersection(t1->next,t2);
        }
        else
            return intersection(t1,t2->next);

        return result;
    }

    void FrontBackSplit(Node* t1,Node** a,Node** b){
        Node* slow=t1;
        Node* fast=t1;
        Node* prev;
        while(fast && fast->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        *a=t1;
        prev->next=NULL;
        *b=slow;
    }

    Node* mergeSort(Node* t1){
        Node* a;
        Node* b;
        if(t1==NULL || t1->next==NULL)
            return t1;
        FrontBackSplit(t1,&a,&b);
        return merge(mergeSort(a),mergeSort(b));
    }

    Node* mergeAlt(Node* t1,Node* t2,int val){
        Node* result;
        if(t1==NULL)
            return t2;
        if(t2==NULL)
            return t1;

        if(val){
            result=t1;
            result->next=mergeAlt(t1->next,t2,0);
        }
        else{
            result=t2;
            result->next=mergeAlt(t1,t2->next,1);
        }
        return result;
    }

    Node* partition(Node* t1,Node** newHead,Node** newEnd){
        Node* pivot=t1;
        while(pivot->next)
            pivot=pivot->next;              // point to last element

        Node* tail=pivot;
        Node* temp=t1;

        *newHead=t1;
        Node* prev=NULL;

        while(temp!=pivot){
            if(temp->data > pivot->data){
                //move to the end
                if(temp==*newHead)
                    *newHead=temp->next;
                Node* newNode=temp;
                temp=temp->next;
                tail->next=newNode;
                if(prev)
                    prev->next=temp;
                newNode->next=NULL;
                tail=newNode;
            }
            else{
                    prev=temp;
                    temp=temp->next;
            }
        }
        *newEnd=tail;

        return pivot;
    }

    Node* quickSort(Node* t1,Node* end){

        if(!t1 || t1==end)
            return t1;

        Node *newHead=NULL,*newEnd=NULL;
        Node *pivot=partition(t1,&newHead,&newEnd);

        // If pivot is the smallest element - no need to recur for
        // the left part.
        if(newHead!=pivot){

            Node* temp=newHead;
            while(temp->next!=pivot)
                temp=temp->next;
            temp->next=NULL;
            newHead=quickSort(newHead,temp);

            while(temp->next)
                temp=temp->next;
            temp->next=pivot;
        }

        pivot->next=quickSort(pivot->next,newEnd);
        return newHead;
    }

    Node* quickSort_helper(Node* head){
        Node* temp=head;
        while(temp->next)
            temp=temp->next;
        return quickSort(head,temp);
    }

int main(){
    l1.InsertAtFront(5);
    l1.InsertAtFront(20);
    l1.InsertAtFront(4);
    l1.InsertAtFront(3);
    l1.InsertAtFront(30);
    //l1.InsertAtFront(2);
    //l1.InsertAtFront(1);
    l1.print();
    l1.head=l1.insertionSort();
    //l1.head=quickSort_helper(l1.head);
    //l1.head=l1.kReverse(l1.head,2);
    //l3.head=mergeAlt(l1.head,l2.head,1);
    //l1.rotate(4);
    //l2.print();
    //l1.deleteMN(3,2);
    //l3.head=l3.add_helper(l1.head,l2.head);
    l1.print();
    // l1.InsertAtMiddle(4,3);
    // l1.InsertAtMiddle(6,5);
    // l1.InsertAtEnd(7);
    // l1.InsertAtEnd(8);
    //l1.print();
    // l1.head=l1.kReverse(l1.head,3);
    // l1.print();
    // l1.head=l1.kReverse(l1.head,3);
    // l1.print();
    // l1.head=l1.kAltReverse(l1.head,3);
    //l1.Segregate();
    //l1.print();
    //l1.print();
    //l1.pairwise_swap();
    //l1.lastTofirst();
    //l1.print();
    // l1.length_helper();
    // l1.deleteNode(3);
    //l1.swapNode(1,6);
    //l1.print();
    // l1.getNth(5);
    // l1.middle();
    // l1.nthFromEnd(6);
    //l1.reverse_helper();
    //l1.print();
    //l1.loop_maker();
    // l1.loop();
    //l1.remove_duplicates();
    //l1.print();
    //l1.print_reverse_helper();
    //for merge ----------------
    // l1.InsertAtFront(7);
    // l1.InsertAtFront(4);
    // l1.InsertAtFront(3);
    // l1.InsertAtFront(1);
    // l2.InsertAtFront(8);
    // l2.InsertAtFront(5);
    // l2.InsertAtFront(2);
    // l1.print();
    // l2.print();
    // l3.head=merge(l1.head,l2.head);
    // l3.print();
    //end of merge --------------

    //for intersection - --------

    // l1.InsertAtEnd(1);
    // l1.InsertAtEnd(2);
    // l1.InsertAtEnd(3);
    // l1.InsertAtEnd(4);
    // l1.InsertAtEnd(6);
    // l2.InsertAtEnd(2);
    // l2.InsertAtEnd(4);
    // l2.InsertAtEnd(6);
    // l2.InsertAtEnd(8);
    // l1.print();
    // l2.print();
    // l3.head=intersection(l1.head,l2.head);
    // l3.print();
    //for finding intersection ------

    // l2.InsertAtFront(10);
    // Insert(15,30);
    // l1.InsertAtFront(9);
    // l1.InsertAtFront(6);
    // l1.InsertAtFront(3);

    // get_intersection(l1.head,l2.head);

    //end of intersection   ---------
    return 0;
}














