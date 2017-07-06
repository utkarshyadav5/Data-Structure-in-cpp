#include <bits/stdc++.h>

using namespace std;

int fac(int n){
    if(n<=0)
        return 1;
    return n*fac(n-1);
}

void IncreaseCount(int *count,char *str){
    for(int i=0;str[i];i++)
        ++count[str[i]];

    for(int i=1;i<256;i++)
        count[i]+=count[i-1];
}

void updateCount(int *count,char ch){
    for(int i=ch;i<256;i++)
        --count[i];
}

int findRank(char *str){
    int len=strlen(str);
    int mul=fac(len);
    int rank=1;

    int count[256]={0};
    IncreaseCount(count,str);

    for(int i=0;i<len;i++){
        mul /= len-1;

        rank+=count[str[i]-1]*mul;
        updateCount(count,str[i]);
    }
    return rank;
}

int main(){
    char str[] = "string";
    printf ("%d\n", findRank(str));
    return 0;
}