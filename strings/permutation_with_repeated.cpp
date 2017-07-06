#include <bits/stdc++.h>

using namespace std;

void allLexicographicRecur(char *str,char *data,int last,int index){
    int len=strlen(str);

    for(int i=0;i<len;i++){

        data[index]=str[i];

        if(index==last)
            cout<<data<<endl;
        else
            allLexicographicRecur(str,data,last,index+1);
    }
}

void allLexicographic(char *str){
    int len=strlen(str);

    char *data = new char[len];
    data[len]='\0';
    sort(str,str+len);

    allLexicographicRecur(str,data,len-1,0);
}

int main(){
    char str[] = "ABC";
    printf("All permutations with repetition of string are: \n");
    allLexicographic(str);
}