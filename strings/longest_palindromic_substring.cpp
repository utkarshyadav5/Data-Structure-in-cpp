#include <bits/stdc++.h>

using namespace std;

int longestPalSubstr(char *str){
    int max_length=1;
    int low,high;
    int start,end;
    int len=strlen(str);
    for(int i=1;i<len;i++){

        //for odd
        low=i-1;
        high=i+1;

        while(low>=0 && high<len && str[low]==str[high]){
            if(high-low+1 > max_length){
                start=low;
                end=high;
                max_length=high-low+1;
            }
            low--;
            high++;
        }

        //for even
        low=i-1;
        high=i;

        while(low>=0 && high<len && str[low]==str[high]){
            if(high-low+1 > max_length){
                start=low;
                end=high;
                max_length=high-low+1;
            }
            low--;
            high++;
        }
    }
    for(int i=start;i<=end;i++)
        cout<<str[i];
    cout<<endl;
    return max_length;
}

int main(){
    char str[] = "forgeeksskeegfor";
    printf("\nLength is: %d\n", longestPalSubstr( str ) );
    return 0;
}