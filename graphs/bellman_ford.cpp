#include <bits/stdc++.h>
#define ipair pair<int,int>

using namespace std;

class Graph{
    int V;
    vector<ipair> *adj;
public:
    Graph(int vertices){
        V=vertices;
        adj = new vector<ipair>[V];
    }

    void addEdge(int u,int v,int weight){
        adj[u].push_back(make_pair(v,weight));
    }

    void bellman(){
        int dist[V];

        dist[0]=0;
        bool change=true;

        for(int i=1;i<V;i++)
            dist[i]=INT_MAX;

        while(change){
            change=false;
            for(int i=0;i<V;i++){
                if(dist[i]==INT_MAX)
                    i++;

                for(int j=0;j<adj[i].size();j++){
                    int v=adj[i][j].first;
                    if(dist[v]>(dist[i]+adj[i][j].second)){
                        dist[v]=dist[i]+adj[i][j].second;
                        change=true;
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

    g.addEdge(0,1,10);
    g.addEdge(0,5,8);
    g.addEdge(1,3,2);
    g.addEdge(2,1,1);
    g.addEdge(3,2,-2);
    g.addEdge(4,3,-1);
    g.addEdge(4,1,-4);
    g.addEdge(5,4,1);
    g.bellman();
    return 0;
}

















