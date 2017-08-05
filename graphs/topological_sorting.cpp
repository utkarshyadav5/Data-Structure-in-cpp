#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

class Graph{
    int V;
    vector<int> *adj;
public:
    stack<int> s;

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

    // Kahn's Algorithm

    void topologicalSort(){

        vector<int> indegree(V,0);

        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++)
                indegree[adj[i][j]]++;
        }

        queue<int> q;
        for(int i=0;i<V;i++)
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty()){
            int top=q.front();
            q.pop();
            cout<<top<<" ";
            for(int i=0;i<adj[top].size();i++){
                indegree[adj[top][i]]--;
                if(indegree[adj[top][i]]==0)
                    q.push(adj[top][i]);
            }
        }
    }

    // Using stack

    void DFS(int u,vector<bool> &visited){
        visited[u]=true;

        for(int i=0;i<adj[u].size();i++)
            if(!visited[adj[u][i]])
                DFS(adj[u][i],visited);

        s.push(u);
    }

    void topologicalSort_stack(){
        vector<bool> visited(V,false);

        for(int i=0;i<V;i++){
            if(!visited[i])
                DFS(i,visited);
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }


};

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of\n";
    g.topologicalSort();
    cout<<endl;
    g.topologicalSort_stack();
    cout<<endl;
    return 0;
}












