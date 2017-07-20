#include <bits/stdc++.h>
#define MAX 1e4

using namespace std;

class Graph{
    int V;
    vector<int> *adj;
    bool *visited;
public:
    Graph(int vertices){
        V=vertices;
        adj= new vector<int>[V];
        visited = new bool[V];
    }

    void addEdge(int u,int v,bool bi){
        if(bi==true){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else
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

    void BFS(){
        bool visited[V]={false};
        queue<int> q;
        q.push(0);
        visited[0]=true;
        cout<<"BFS : ";
        while(!q.empty()){
            int top=q.front();
            q.pop();
            cout<<top<<" ";
            for(int i=0;i<adj[top].size();i++){
                if(visited[adj[top][i]]==false){
                    q.push(adj[top][i]);
                    visited[adj[top][i]]=true;
                }
            }
        }
        cout<<endl;
    }

    void DFS_recursive_util(int s){
        if(visited[s]==true)
            return;

        cout<<s<<" ";
        visited[s]=true;
        for(int i=0;i<adj[s].size();i++){
            if(visited[adj[s][i]]==false){
                DFS_recursive_util(adj[s][i]);
            }
        }
    }

    void DFS_recursive(){
        for(int i=0;i<V;i++)
            visited[i]=false;

        cout<<"DFS : ";
        DFS_recursive_util(0);
        cout<<endl;
    }

    void DFS_iterative(){
        bool visited[V]={false};
        stack<int> s;
        s.push(0);
        visited[0]=true;
        cout<<"DFS Iterative : ";
        while(!s.empty()){
            int top=s.top();
            s.pop();
            cout<<top<<" ";
            for(int i=adj[top].size()-1;i>=0;i--){
                if(visited[adj[top][i]]==false){
                    visited[adj[top][i]]=true;
                    s.push(adj[top][i]);
                }
            }
        }
        cout<<endl;
    }

};

int main(){
    int n=5;
    Graph g(n);

    g.addEdge(0,1,false);
    g.addEdge(0,4,false);
    g.addEdge(1,2,false);
    g.addEdge(1,3,false);
    g.addEdge(1,4,false);
    g.addEdge(2,3,false);
    g.addEdge(3,4,false);

    g.print();
    g.BFS();
    g.DFS_recursive();
    g.DFS_iterative();
    return 0;
}












