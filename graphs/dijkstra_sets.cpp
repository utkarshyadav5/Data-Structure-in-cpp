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
        set<ipair> s;
        vector<int> dist(V,INT_MAX);

        dist[0]=0;
        s.insert(make_pair(0,0));

        while(!s.empty()){
            ipair top=*(s.begin());
            s.erase(s.begin());

            int u=top.second;
            vector<ipair>::iterator it;
            for(it=adj[u].begin();it!=adj[u].end();it++){
                int v=(*it).first;
                int weight=(*it).second;

                if(dist[v]>dist[u]+weight){

                    if(dist[v]!=INT_MAX)
                        s.erase(s.find(make_pair(dist[v],v)));

                    dist[v]=dist[u]+weight;
                    s.insert(make_pair(dist[v],v));
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

















