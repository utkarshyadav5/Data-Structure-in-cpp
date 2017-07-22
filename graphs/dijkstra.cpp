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

    void dijkstra(){
        priority_queue<ipair,vector<ipair>,greater<ipair> > pq;
        vector<int> dist(V,INT_MAX);

        dist[0]=0;
        pq.push(make_pair(0,0));

        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();

            vector<ipair>::iterator it;
            for(it=adj[u].begin();it!=adj[u].end();it++){
                int v=(*it).first;
                int weight=(*it).second;

                if(dist[v]>dist[u]+weight){
                    dist[v]=dist[u]+weight;
                    pq.push(make_pair(dist[v],v));
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
    g.dijkstra();
    return 0;
}

















