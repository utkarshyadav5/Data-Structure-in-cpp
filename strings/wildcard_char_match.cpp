#include <bits/stdc++.h>

using namespace std;

bool match(char *a,char *b){
    if(*a=='\0' && *b=='\0')
        return true;

    if(*a=='*' && *(a+1)!='\0' && *b=='\0')
        return false;

    if(*a=='?' || *a==*b)
        return match(a+1,b+1);

    if(*a=='*')
        return match(a+1,b) || match(a,b+1);
    return false;
}

bool test(char* a,char *b){
    return match(a,b);
}

int main(){
    cout<<test("g*ks", "geeks")<<endl; // Yes
    cout<<test("ge?ks*", "geeksforgeeks")<<endl; // Yes
    cout<<test("g*k", "gee")<<endl;  // No because 'k' is not in second
    cout<<test("*pqrs", "pqrst")<<endl; // No because 't' is not in first
    cout<<test("abc*bcd", "abcdhghgbcd")<<endl; // Yes
    cout<<test("abc*c?d", "abcd")<<endl; // No because second must have 2
                             // instances of 'c'
    cout<<test("*c*d", "abcd")<<endl; // Yes
    cout<<test("*?c*d", "abcd")<<endl; // Yes
    return 0;
}