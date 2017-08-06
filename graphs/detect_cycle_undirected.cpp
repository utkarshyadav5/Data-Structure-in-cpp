#include <bits/stdc++.h>
#define iPair pair<int,int>

using namespace std;

class Graph{
    int V;
    int E;
    vector<iPair> adj;
public:
    vector<int> arr;

    Graph(int vertices){
        V=vertices;
        E=0;
        for(int i=0;i<V;i++)
            arr.push_back(i);
    }

    void addEdge(int u,int v){
            adj.push_back(make_pair(u,v));
    }

    void print(){
        cout<<adj.size()<<endl;
        for(int i=0;i<adj.size();i++)
            cout<<adj[i].first<<" "<<adj[i].second<<endl;
    }

    int root(int i){
        while(i!=arr[i]){
            arr[i]=arr[arr[i]];
            i=arr[i];
        }
        return i;
    }

    void union_(int a,int b){
        int root_a=root(a);
        int root_b=root(b);
        arr[root_a]=root_b;
    }

    bool find(int a,int b){
        if(root(a)==root(b))
            return true;
        else
            return false;
    }

    bool isCyclic(){
        for(int i=0;i<adj.size();i++){
            int u=adj[i].first;
            int v=adj[i].second;
            if(find(u,v))
                return true;
            union_(u,v);
        }
        return false;
    }



};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    //g.print();
    if(g.isCyclic())
        cout << "Graph contains cycle"<<endl;
    else
        cout << "Graph doesn't contain cycle"<<endl;
    return 0;
}












