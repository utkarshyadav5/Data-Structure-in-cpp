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

    void floyd(){
        int dist[V][V];

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                dist[i][j]=INT_MAX;
            }
        }

        for(int i=0;i<V;i++)
            dist[i][i]=0;

        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                dist[i][adj[i][j].first]=adj[i][j].second;
            }
        }

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++)
                cout<<dist[i][j]<<" ";
            cout<<endl;
        }

        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(dist[i][j]>(dist[i][k]+dist[k][j]))
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++)
                cout<<dist[i][j]<<" ";
            cout<<endl;
        }
    }
};

int main(){
    Graph g(6);

    g.addEdge(0,1,10);
    g.addEdge(0,5,8);
    g.addEdge(1,3,2);
    g.addEdge(2,1,1);
    g.addEdge(3,2,2);
    g.addEdge(4,3,1);
    g.addEdge(4,1,4);
    g.addEdge(5,4,1);
    g.floyd();
    return 0;
}

















