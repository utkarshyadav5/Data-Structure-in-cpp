#include <bits/stdc++.h>

using namespace std;

void permuteUtil(char *str,char *output,int index,int n){
    if(index==n){
        cout<<output<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        output[index]=str[i];
        permuteUtil(str,output,index+1,n);
    }
}

void permute(char *str){
    int len=strlen(str);

    char *output = new char[len+1];
    output[len]='\0';
    sort(str,str+len);

    permuteUtil(str,output,0,len);
}

int main(){
    char str[] = "ABC";
    printf("All permutations with repetition of string are: \n");
    permute(str);
}