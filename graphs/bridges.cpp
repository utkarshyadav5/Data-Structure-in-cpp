#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

bool visited[MAX];
int d_time[MAX],low_time[MAX];
int parent[MAX];

class Graph{
    int V;
    int time;
    vector<int> *adj;
public:
    Graph(int vertices){
        V=vertices;
        time=0;
        adj = new vector<int>[V];
    }

    void addEdge(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            for(int j=0;j<adj[i].size();j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;
        }
    }

    // Rule 1 : discovery time of vertex <= lowest time of any of its child

    void DFS(int u){
        visited[u]=true;
        d_time[u]=low_time[u]=++time;
        int child=0;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(!visited[v]){
                child++;
                parent[v]=u;
                DFS(v);
                low_time[u]=min(low_time[u],low_time[v]);

                if(d_time[u]<low_time[v])
                    cout<<u<<" "<<v<<endl;
            }
            else if(parent[u]!=v)
                low_time[u]=min(low_time[u],d_time[v]);
        }
    }

    void AP(){
        for(int i=0;i<V;i++){
            visited[i]=false;
            low_time[i]=INT_MAX;
            parent[i]=-1;
        }

        for(int i=0;i<V;i++)
            if(!visited[i])
                DFS(i);
    }


};

int main(){
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    cout<<"Bridges are :"<<endl;
    g3.AP();
    return 0;
}












