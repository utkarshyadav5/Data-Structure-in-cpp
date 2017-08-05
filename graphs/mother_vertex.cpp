#include <bits/stdc++.h>
#define MAX 1e4

using namespace std;

class Graph{
    int V;
    vector<int> *adj;
public:
    Graph(int vertices){
        V=vertices;
        adj= new vector<int>[V];
    }

    void addEdge(int u,int v){
            adj[u].push_back(v);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            for(int j=0;j<adj[i].size();j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;
        }
    }

    void DFS_Util(int v,vector<bool> &visited){
        visited[v]=true;

        for(int i=0;i<adj[v].size();i++)
            if(visited[adj[v][i]]==false)
                DFS_Util(adj[v][i],visited);

    }

    int findMother(){
        vector<bool> visited(V,false);

        int v=0;

        for(int i=0;i<V;i++){
            if(visited[i]==false){
                DFS_Util(i,visited);
                v=i;
            }
        }

        //check whether v is mother vertex or not
        fill(visited.begin(),visited.end(),false);
        DFS_Util(v,visited);
        for(int i=0;i<V;i++)
            if(visited[i]==false)
                return -1;
        return v;
    }



};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout << "A mother vertex is " << g.findMother()<<endl;
    return 0;
}












