#include <bits/stdc++.h>
#define ROW 4
#define COL 5

using namespace std;

class Node{
    bool isLeaf;
    Node* child[2];
public:
    Node(){
        isLeaf=false;
        child[0]=child[1]=NULL;
    }

    Node* makeNode(){
        Node *newNode = new Node();
        return newNode;
    }

    bool insert(Node* root,bool (*M)[5],int r,int c){
        bool val=false;

        for(int i=0;i<c;i++){
            if(!root->child[M[r][i]]){
                root->child[M[r][i]]=makeNode();
                val=true;
            }
            root=root->child[M[r][i]];
        }
        return val;
    }


};

void print(bool (*M)[5],int r,int c){
    for(int i=0;i<c;i++)
        cout<<M[r][i]<<" ";
    cout<<endl;
}

void findUniqueRows(bool (*M)[5],int r,int c){
    Node n;
    Node *root = n.makeNode();

    for(int i=0;i<r;i++){
        if(n.insert(root,M,i,c))
            print(M,i,c);
    }

}

int main()
{
    bool M[ROW][COL] = {{0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0}
    };

    findUniqueRows( M,4,5);

    return 0;
}