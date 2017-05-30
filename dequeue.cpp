#include <bits/stdc++.h>
#define MAX 100

using namespace std;

class Dequeue{
    int arr[MAX];
    int count;
    int size;
    int front;
    int rear;

public:
    Dequeue(int arrsize){
        size=arrsize;
        front=0;
        rear=(-1);
        count=0;
    }

    void insertFront(int data){
        if(count==size)
            cout<<"Overflow"<<endl;

        else{
            front=(front-1);
            if(front<0)
                front=size-1;
            arr[front]=data;
            count++;
        }
    }

    void insertRear(int data){
        if(count==size)
            cout<<"Overflow"<<endl;

        else{
            rear=(rear+1)%size;
            arr[rear]=data;
            count++;
        }
    }

    void deleteFront(){
        if(count==0)
            cout<<"Underflow"<<endl;

        else{
            arr[front]=0;
            front=(front+1)%size;
            count--;
        }
    }

    void deleteRear(){
        if(count==0)
            cout<<"Underflow"<<endl;

        else{
            arr[rear]=0;
            rear=rear-1;
            if(rear<0)
                rear=size-1;
            count--;;
        }
    }

    int getFront(){
        return arr[front];
    }

    int getRear(){
        return arr[rear];
    }

    bool isEmpty(){
        if(count)
            return false;
        else
            return true;
    }

    bool isFull(){
        if(count==size)
            return true;
        else
            return false;
    }

    void print(){
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

};

int main(){
    Dequeue d1(8);

    d1.insertRear(10);
    d1.insertRear(15);
    d1.insertRear(20);
    d1.insertRear(30);
    d1.insertFront(70);
    d1.insertFront(60);
    d1.insertFront(50);
    d1.insertFront(10);
    d1.print();
    cout<<d1.isEmpty()<<endl;
    cout<<d1.isFull()<<endl;
    d1.insertFront(10);
    d1.print();
    cout<<d1.isEmpty()<<endl;
    cout<<d1.isFull()<<endl;
    d1.deleteFront();
    d1.deleteFront();
    d1.print();
    d1.deleteRear();
    d1.deleteRear();
    d1.print();
    return 0;
}

























