#include <bits/stdc++.h>
#define MAX 10000
#define iPair pair<int,int>

using namespace std;

class Graph{
    int V;
    vector<iPair> *adj;
public:
    Graph(int vertices){
        V=vertices;
        adj= new vector<iPair>[V];
    }

    void addEdge(int u,int v,int weight){
            adj[u].push_back(make_pair(v,weight));
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            for(int j=0;j<adj[i].size();j++)
                cout<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
        }
        cout<<endl;
    }

    void longestPath(int src){

        int dist[V];
        for(int i=0;i<V;i++)
            dist[i]=INT_MIN;

        queue<int> q;
        q.push(src);
        dist[src]=0;

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(int i=0;i<adj[top].size();i++){
                iPair curr=adj[top][i];
                if(dist[top]!=INT_MIN){
                    if(dist[curr.first]<dist[top]+curr.second){
                        dist[curr.first]=dist[top]+curr.second;
                        q.push(curr.first);
                    }
                }
            }
        }

        for(int i=0;i<V;i++)
            cout<<dist[i]<<" ";
        cout<<endl;
    }



};

int main(){
    Graph g(6);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.print();
    int s = 1;
    cout << "Following are longest distances from source vertex " << s <<" \n";
    g.longestPath(s);
    cout<<endl;
    return 0;
}












