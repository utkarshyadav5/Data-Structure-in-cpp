#include <bits/stdc++.h>

using namespace std;

int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

class Heap{
    int *arr;
    int heap_size;
    int capacity;
public:
    Heap(int size){
        capacity=size;
        heap_size=0;
        arr=new int[capacity];
    }

    int parent(int i){ return (i-1)/2; };
    int left(int i){ return 2*i+1; };
    int right(int i){ return 2*i+2; };
    int getMin(){ return arr[0]; };

    int Minheapify(int i){
        int l=left(i);
        int r=right(i);
        int smallest=i;

        if(l<heap_size && arr[l]<arr[smallest])
            smallest=l;
        if(r<heap_size && arr[r]<arr[smallest])
            smallest=r;
        if(smallest!=i){
            swap(&arr[i],&arr[smallest]);
            Minheapify(smallest);
        }
    }

    void insert(int k){
        if(heap_size==capacity)
            return;

        heap_size++;
        int i=heap_size-1;
        arr[i]=k;

        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(&arr[parent(i)],&arr[i]);
            i=parent(i);
        }
    }

    int extractMin(){
        if(heap_size<=0)
            return INT_MAX;
        if(heap_size==1){
            heap_size--;
            return arr[0];
        }

        int root=arr[0];
        arr[0]=arr[heap_size-1];
        heap_size--;
        Minheapify(0);

        return root;
    }

    void decreaseKey(int i,int new_value){
        arr[i]=new_value;
        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(&arr[parent(i)],&arr[i]);
            i=parent(i);
        }
    }

    void deleteKey(int i){
        decreaseKey(i,INT_MIN);
        extractMin();
    }
};

int main(){
    Heap h(11);
    h.insert(3);
    h.insert(2);
    h.deleteKey(1);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    cout << h.extractMin()<<endl;
    cout << h.getMin()<<endl;
    h.decreaseKey(2, 1);
    cout<<h.getMin()<<endl;
    return 0;
}


















