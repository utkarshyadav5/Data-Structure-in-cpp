#include <bits/stdc++.h>
#define MAX 1e4

using namespace std;

class Graph{
    int V;
    vector<int> *adj;
public:
    bool *visited;
    bool *recStack;
    int *color;
    enum Color{WHITE,GREY,BLACK};

    Graph(int vertices){
        V=vertices;
        adj= new vector<int>[V];
        visited = new bool[V];
        recStack = new bool[V];
        color = new int[V];
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

    ///////////////// - Method 1 - ////////////////////////////

    // bool isCyclic_Util(int u){
    //     if(visited[u]==false){
    //         visited[u]=true;
    //         recStack[u]=true;

    //         for(int i=0;i<adj[u].size();i++){
    //             int v=adj[u][i];
    //             if(!visited[v] && isCyclic_Util(v))
    //                 return true;
    //             else if(recStack[v])
    //                 return true;
    //         }
    //     }
    //     recStack[u]=false;
    //     return false;
    // }

    // bool isCyclic(){
    //     for(int i=0;i<V;i++){
    //         visited[i]=false;
    //         recStack[i]=false;
    //     }

    //     for(int i=0;i<V;i++)
    //         if(isCyclic_Util(i))
    //             return true;

    //     return false;
    // }

    ////////////////////////////////////////////////////////

    ///////////////////// - Method 2 - /////////////////////

    bool isCyclic_Util(int u){

        if(color[u]==WHITE){
            color[u]=GREY;

            for(int i=0;i<adj[u].size();i++){
                int v=adj[u][i];

                if(color[v]==GREY)
                    return true;

                if(color[v]==WHITE && isCyclic_Util(v))
                    return true;
            }
        }
        color[u]=BLACK;
        return false;
    }

    bool isCyclic(){
        for(int i=0;i<V;i++)
            color[i]=WHITE;

        for(int i=0;i<V;i++)
            if(isCyclic_Util(i))
                return true;

        return false;
    }

    ////////////////////////////////////////////////////////

};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCyclic())
        cout << "Graph contains cycle"<<endl;
    else
        cout << "Graph doesn't contain cycle"<<endl;
    return 0;
    return 0;
}












