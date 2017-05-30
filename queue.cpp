#include <bits/stdc++.h>

using namespace std;

class Queue;

class Node{
    int data;
    Node* next;
    friend class Queue;
public:
    Node(): data(0),next(NULL){}
    Node(int val): data(val),next(NULL){}
};

class Queue
{
    Node* head;
    Node* tail;
public:
    Queue(): head(NULL),tail(NULL){}

    void enqueue(int data){
        Node* newNode=new Node(data);
        if(head==NULL)
            head=tail=newNode;
        else{
            tail->next=newNode;
            tail=tail->next;
        }
    }

    void dequeue(){
        if(head==NULL)
            cout<<"Empty queue"<<endl;
        else{
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }

    int front(){
        return head->data;
    }

    int rear(){
        return tail->data;
    }

    void print(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.print();
    q1.dequeue();
    q1.print();
    cout<<q1.front()<<endl;
    cout<<q1.rear()<<endl;
    return 0;
}













