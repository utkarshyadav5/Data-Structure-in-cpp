#include <bits/stdc++.h>

using namespace std;

char* removeDupUtil(char* str,char *last_removed){

    //if string is of length 1 or 0
    if(str[0]=='\0' || str[1]=='\0')
        return str;

    //if first two chars are same remove them
    if(str[0]==str[1]){
        *last_removed=str[0];
        while(str[1] && str[0]==str[1])
            str++;
        str++;             // this increase in str ignores the first char which was same
        return removeDupUtil(str,last_removed);
    }

    // At this point, the first character is definitely different
    // from its adjacent. Ignore first character and recursively
    // remove characters from remaining string
    char *rem_str=removeDupUtil(str+1,last_removed);

    //Case 1: if str[0] matches with rem_str[0]
    if(rem_str[0] && str[0]==rem_str[0]){
        *last_removed=str[0];
        return (rem_str+1);
    }

    //Case 2: if rem_str is null and last removed is same as str[0]
    if(rem_str[0]=='\0' && *last_removed==str[0])
        return rem_str;

    //Case 3: if they dont match append rem_str to str
    rem_str--;
    rem_str[0]=str[0];
    return rem_str;
}

char *removeDup(char* str,int n){
    char last_removed='\0';
    return removeDupUtil(str,&last_removed);
}

int main(){
    char str1[] = "geeksforgeeg";
    cout << removeDup(str1, strlen(str1)) << endl;

    char str2[] = "azxxxzy";
    cout << removeDup(str2, strlen(str2)) << endl;

    char str3[] = "caaabbbaac";
    cout << removeDup(str3, strlen(str3)) << endl;

    char str4[] = "gghhg";
    cout << removeDup(str4, strlen(str4)) << endl;

    char str5[] = "aaaacddddcappp";
    cout << removeDup(str5, strlen(str5)) << endl;

    char str6[] = "aaaaaaaaaa";
    cout << removeDup(str6, strlen(str6)) << endl;

    char str7[] = "qpaaaaadaaaaadprq";
    cout << removeDup(str7, strlen(str7)) << endl;

    char str8[] = "acaaabbbacdddd";
    cout << removeDup(str8, strlen(str8)) << endl;

    char str9[] = "acbbcddc";
    cout << removeDup(str9, strlen(str9)) << endl;
    return 0;
}