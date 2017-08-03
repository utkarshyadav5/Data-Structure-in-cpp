#include <bits/stdc++.h>
#define R 4
#define C 4

using namespace std;

int getMaxArea(int arr[],int n){
    stack<int> s;

    int max_len=-1;
    int area,tp,i=0;

    while(i<n){
        if(s.empty()|| arr[s.top()]<=arr[i])
            s.push(i++);

        else{
            tp=s.top();
            s.pop();

            if(s.empty())
                area=arr[tp]*i;
            else
                area=arr[tp]*(i-s.top()-1);

            max_len=max(max_len,area);
        }
    }

    while(!s.empty()){
        tp=s.top();
        s.pop();

        if(s.empty())
            area=arr[tp]*i;
        else
            area=arr[tp]*(i-s.top()-1);

        max_len=max(max_len,area);
    }

    return max_len;
}

int maxRectangle(int arr[][C]){

    int max_rect=-1;

    max_rect=max(max_rect,getMaxArea(arr[0],4));

    for(int i=1;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==1)
                arr[i][j]=arr[i-1][j]+1;
        }
        max_rect=max(max_rect,getMaxArea(arr[i],4));
    }

    return max_rect;
}

int main(){
    int A[][C] = { {0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0},
                 };

    cout << "Area of maximum rectangle is "
         << maxRectangle(A)<<endl;

    return 0;
}