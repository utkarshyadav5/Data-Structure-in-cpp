#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

// ----------- Disjoint Set --------------

int arr[MAX];

void initialise(int n){
    for(int i=0;i<n;i++)
        arr[i]=i;
}

int root(int i){
    while(arr[i]!=i){
        arr[i]=arr[arr[i]];
        i=arr[i];
    }
    return i;
}

void union_(int a,int b){
    int root_a=arr[a];
    int root_b=arr[b];
    arr[root_a]=root_b;
}

bool find(int a,int b){
    if(root(a)==root(b))
        return true;
    else
        return false;
}

// ----------- End -----------------------

class Graph{
    int V;
    int E;
    vector< pair<int, pair<int,int> > > adj;
public:
    Graph(int vertices,int edges){
        V=vertices;
        E=edges;
    }

    void addEdge(int u,int v,int weight){
            adj.push_back(make_pair(weight,make_pair(u,v)));
    }

    void arrange(){
        sort(adj.begin(),adj.end());
        //print();
    }

    void print(){
        for(int i=0;i<E;i++){
            int weight=adj[i].first;
            int from=adj[i].second.first;
            int to=adj[i].second.second;
            cout<<weight<<" : "<<from<<" "<<to<<endl;
        }
    }

    void kruskal(){
        initialise(V);

        int minCost=0;
        vector< pair<int, pair<int,int> > >::iterator it;
        cout<<"MST : "<<endl;
        for(it=adj.begin();it!=adj.end();it++){
            int weight=(*it).first;
            int from=(*it).second.first;
            int to=(*it).second.second;
            if(root(from)!=root(to)){
                cout<<from<<" "<<to<<endl;
                minCost+=weight;
                union_(from,to);
            }
        }
        cout<<minCost<<endl;
    }

};

int main(){
    Graph g(9,14);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    //g.print();
    g.arrange();
    g.kruskal();

    return 0;
}












