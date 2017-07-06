#include <bits/stdc++.h>

using namespace std;

string findSubString(string str,string pat){

    if(pat.length()>str.length())
        return "";

    int myStr[256]={0};
    int myPat[256]={0};

    for(int i=0;i<pat.length();i++)
        myPat[pat[i]]++;

    int start=0,index_start=-1,min_len=INT_MAX,count=0;

    for(int i=0;i<str.length();i++){
        myStr[str[i]]++;

        if(myPat[str[i]]!=0 && myStr[str[i]]<=myPat[str[i]])
            count++;

        if(count==pat.length()){
            //minimize the window
            while(myStr[str[start]] > myPat[str[start]] || myPat[str[start]]==0){

                if(myStr[str[start]] > myPat[str[start]])
                    myStr[str[start]]--;
                start++;

            }
            int len_window = i-start+1;
            if(min_len > len_window){
                min_len=len_window;
                index_start=start;
            }
        }
    }

    return str.substr(index_start,min_len);
}

int main(){
    string str;
    string pat;
    getline(cin,str);
    getline(cin,pat);
    cout << "Smallest window is : "
         << findSubString(str, pat)<<endl;
    return 0;
}