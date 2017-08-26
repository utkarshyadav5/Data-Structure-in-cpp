#include <bits/stdc++.h>

using namespace std;

class hashNode{
public:
    char *key;
    int value;
    hashNode* next;

    hashNode(char *k,int val){
        key=new char[strlen(k)+1];
        strcpy(key,k);
        value=val;
        next=NULL;
    }

    ~hashNode(){
        if(next!=NULL)
            delete next;
        delete [] key;
    }
};

class hashTable{
    int curr_size;
    int table_size;
    hashNode **buckets;

    int hashFunc(char *key){
        int index=0;
        int power=1;
        int L=strlen(key);

        for(int i=0;i<L;i++){
            index += key[L-i-1]*power;
            index %= table_size;
            power *= 37;
        }
        return index;
    }

    void rehash(){
        int old_size=table_size;
        hashNode **old_bucket=buckets;

        curr_size=0;
        table_size = 2*table_size;
        buckets = new hashNode*[table_size];

        for(int i=0;i<table_size;i++)
            buckets[i]=NULL;

        for(int i=0;i<old_size;i++){
            if(old_bucket[i]!=NULL){
                hashNode *temp=old_bucket[i];

                while(temp!=NULL){
                    insert(temp->key,temp->value);
                    temp=temp->next;
                }
                delete old_bucket[i];
            }
        }

    }

public:
    hashTable(){
        curr_size=0;
        table_size=3;
        buckets = new hashNode*[table_size];
        for(int i=0;i<table_size;i++)
            buckets[i]=NULL;
    }

    void insert(char *k,int val){
        int i=hashFunc(k);

        hashNode* temp=new hashNode(k,val);
        temp->next=buckets[i];
        buckets[i]=temp;
        curr_size++;

        float load_factor = curr_size/(float)table_size;
        if(load_factor>0.7){
            cout<<"Load factor is "<<load_factor<<endl;
            rehash();
        }
    }

    void find(char *k){
        int i=hashFunc(k);
        hashNode *temp=buckets[i];

        while(temp!=NULL && temp->key!=k){
            if(strcmp(temp->key,k)==0){
                cout<<"Bucket found at "<<index<<" "<<temp->key<<" "<<temp->value<<endl;
            }
            temp=temp->next;
        }
    }

    void print(){
        for(int i=0;i<table_size;i++){
            cout<<"Bucket-->"<<i<<" ";
            if(buckets[i]!=NULL){
                hashNode *temp = buckets[i];
                while(temp!=NULL){
                    cout<<temp->key<<"-->"<<temp->value<<" ";
                    temp=temp->next;
                }
            }
            cout<<endl;
        }
    }

    void remove(char *k){
        int index=hashFunc(k);
        hashNode *temp=buckets[index];

        if(temp==NULL)
            cout<<"Not present"<<endl;
        else if(temp->next==NULL && strcmp(temp->key,k)==0){
            buckets[index]=NULL;
            delete [] temp->key;
        }
        else if(temp->next!=NULL && strcmp(temp->key,k)==0){
            buckets[index]=temp->next;
            delete [] temp->key;
        }
        else{
            hashNode *temp_next=temp->next;
            while(temp_next!=NULL && strcmp(temp_next->key,k)!=0){
                temp=temp_next;
                temp_next=temp_next->next;
            }
            if(temp_next==NULL)
                cout<<"Not found"<<endl;
            else{
                temp->next=temp_next->next;
                delete [] temp_next->key;
            }
        }
    }

    ~hashTable(){
        for(int i=0;i<table_size;i++)
            if(buckets[i]!=NULL)
                delete buckets[i];

        delete [] buckets;
        buckets=NULL;
    }

};

int main()
{
    hashTable l1;
    l1.insert("prate",120);
    l1.print();
    l1.insert("mohit",199);
    l1.print();
    l1.insert("hutkars",220);
    l1.print();
    l1.insert("tohi",342);
    l1.print();
    l1.insert("moith",232);
    l1.print();
    l1.insert("tohim",342);
    l1.print();

    l1.print();
    l1.find("hutkars");
    l1.remove("prate"); // for testing case 1
    l1.remove("tohim"); // for testing case 2
    l1.print();
    l1.insert("etapr",120);
    l1.print();
    l1.remove("mohit");
    cout<<endl;
    l1.remove("moith");
    l1.print();
    return 0;
}














