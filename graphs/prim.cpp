#include <bits/stdc++.h>
#define MAX 1e4

using namespace std;

typedef pair<int,int> iPair;

class Graph{
    int V;
    vector<iPair> *adj;
public:
    Graph(int vertices){
        V=vertices;
        adj= new vector<iPair>[V];
    }

    void addEdge(int u,int v,int weight){
            adj[u].push_back(make_pair(weight,v));
            adj[v].push_back(make_pair(weight,u));
    }

    void primMST(int start){
        bool visited[V]={false};
        priority_queue<iPair,vector<iPair>,greater<iPair> > q;
        q.push(make_pair(0,start));
        int min_cost=0;

        while(!q.empty()){
            iPair top=q.top();
            q.pop();
            int x=top.second;
            if(visited[x])
                continue;
            visited[x]=true;
            min_cost+=top.first;
            for(int i=0;i<adj[x].size();i++){
                if(visited[adj[x][i].second]==false)
                    q.push(adj[x][i]);
            }

        }
        cout<<min_cost<<endl;
    }

    // void print(){
    //     for(int i=0;i<V;i++){
    //         cout<<i<<" : ";
    //         for(int j=0;j<adj[i].size();j++)
    //             cout<<adj[i][j]<<" ";
    //         cout<<endl;
    //     }
    // }

};

int main(){
    Graph g(9);

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

    g.primMST(0);

    return 0;
}












