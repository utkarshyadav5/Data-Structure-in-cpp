#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

class Graph{
    int tc[MAX][MAX];
    int V;
    vector<int> *adj;
public:
    Graph(int vertices){
        V=vertices;
        adj= new vector<int>[V];

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++)
                tc[i][j]=0;
        }
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

    void DFS_Util(int u,int v){
        tc[u][v]=1;

        for(int i=0;i<adj[v].size();i++)
            if(tc[u][adj[v][i]]==0)
                DFS_Util(u,adj[v][i]);

    }

    void transitiveClosure(){

        for(int i=0;i<V;i++)
            DFS_Util(i,i);

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++)
                cout<<tc[i][j]<<" ";
            cout<<endl;
        }
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

    cout << "Transitive closure matrix is \n";
    g.transitiveClosure();
    return 0;
}












