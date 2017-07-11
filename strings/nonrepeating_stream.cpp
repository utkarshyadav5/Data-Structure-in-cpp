#include <bits/stdc++.h>
#define MAX 256

using namespace std;

// cannot use stl as remove takes linear time.implement dll in this
// ques and inDLL array store the location of dll so that remove
// works in O(1). Even if we use erase we cant assign the location
// in inDLL array.

void findFirstNonRepeating(){
    list<char> myList;
    bool repeated[MAX]={false};
    list<char>::iterator inDLL[MAX];

    char stream[]="geeksforgeeksandgeeksquizfor";

    for(int i=0;stream[i];i++){
        if(repeated[stream[i]]==false){
            if(inDLL[stream[i]]==myList.end()){
                myList.push_back(stream[i]);
                inDLL[stream[i]]=myList.end();
            }
            else{
                myList.erase(inDLL[stream[i]]);
                repeated[stream[i]]=true;
            }
        }
        cout<<myList.front()<<endl;
    }
}

int main(){
    findFirstNonRepeating();
    return 0;
}