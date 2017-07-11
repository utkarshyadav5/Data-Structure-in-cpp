#include <bits/stdc++.h>

using namespace std;

char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

void printWordsUtil(int number[],int curr,char output[],int n){
    if(curr==n){
        cout<<output<<endl;
        return;
    }

    for(int i=0;i<strlen(hashTable[number[curr]]);i++){
        output[curr]=hashTable[number[curr]][i];
        printWordsUtil(number,curr+1,output,n);
        if(number[curr]==0 || number[curr]==1)
            return;
    }
}

void printWords(int number[],int n){
    char result[n+1];
    result[n]='\0';
    printWordsUtil(number,0,result,n);
}

int main(){
    int number[] = {2, 3, 4};
    int n = sizeof(number)/sizeof(number[0]);
    printWords(number, n);
    return 0;
}