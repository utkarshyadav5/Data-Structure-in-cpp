#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[]={6,2,5,4,5,1,6};
    int area,max_area=0,top,i;
    stack<int> stk;

    while(i<7){
        if(stk.empty() || arr[i]>=arr[stk.top()])
            stk.push(i++);
        else{
            top=stk.top();
            stk.pop();

            if(stk.empty())
                area=arr[top]*i;
            else
                area=arr[top]*(i-stk.top()-1);
            cout<<area<<" "<<max_area<<endl;
            max_area=max(area,max_area);
        }
    }
    while(!stk.empty()){
        top=stk.top();
        stk.pop();

        if(stk.empty())
            area=arr[top]*i;
        else
            area=arr[top]*(i-stk.top()-1);

        max_area=max(area,max_area);
    }
    cout<<max_area<<endl;
    return 0;
}









