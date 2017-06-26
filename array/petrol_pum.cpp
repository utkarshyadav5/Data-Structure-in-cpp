#include <bits/stdc++.h>

using namespace std;

class petrolPump{
public:
    int petrol;
    int dist;
};

int printTour(petrolPump arr[],int n){
    int start=0,end=1;
    int curr_petrol=arr[0].petrol-arr[0].dist;

    while(start!=end || curr_petrol<0){

        while(curr_petrol<0 && start!=end){

            curr_petrol-=(arr[start].petrol-arr[start].dist);
            start=(start+1)%n;

            if(start==0)
                return -1;
        }

        curr_petrol+=(arr[end].petrol-arr[end].dist);
        end=(end+1)%n;
    }
    return start;
}

int main(){
    petrolPump arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};

    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1)? printf("No solution\n"): printf("Start = %d\n", start);
    return 0;
}





















