#include <bits/stdc++.h>

using namespace std;

class LinkedList;

class Node{
    int data;
    Node* next;
public:
    Node(): data(0),next(NULL){}
    Node(int value): data(value),next(NULL){}
    friend class LinkedList;
};

class LinkedList{
    Node* head;
public:
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

};


int main(){
    LinkedList l1;
    l1.InsertAtFront(5);
    l1.InsertAtFront(3);
    l1.InsertAtFront(2);
    l1.InsertAtFront(1);
    l1.InsertAtMiddle(4,3);
    l1.InsertAtMiddle(6,5);
    l1.InsertAtEnd(7);
    l1.InsertAtEnd(8);
    l1.print();
    l1.length_helper();
    // l1.deleteNode(3);
    //l1.swapNode(1,6);
    //l1.print();
    l1.getNth(5);
    l1.middle();
    l1.nthFromEnd(6);
    return 0;
}














