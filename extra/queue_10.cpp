#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,rem=0,total_petrol,total_dist;
    bool flag=false;
    int arr_petrol[4],arr_dist[4];
    queue< pair<int,int> > q;
    for(int i=0;i<4;i++){
        cin>>a>>b;
        arr_petrol[i]=a;
        arr_dist[i]=b;
        q.push(make_pair(a,b));
    }
    pair<int,int> start=q.front();
    do{
        total_petrol=q.front().first+rem;
        total_dist=q.front().second;
        if(total_petrol<total_dist){
            rem=0;
            q.push(q.front());
            q.pop();
            start=q.front();
            flag=false;
        }
        else{
            flag=true;
            rem=total_petrol-total_dist;
            q.push(q.front());
            q.pop();
        }

    }while(start!=q.front() || flag!=true);

    int count=0;
    for(int i=0;i<4;i++){
        if(arr_petrol[i]==(start.first) && arr_dist[i]==(start.second)){
            cout<<count<<endl;
            break;
        }
        else
            count++;
    }

    return 0;
}
















