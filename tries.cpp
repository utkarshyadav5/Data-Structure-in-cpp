#include <bits/stdc++.h>

using namespace std;

class TrieNode{
public:
    char data;
    map<char,TrieNode*> myMap;
    bool isEnd;

    TrieNode(char d){
        data=d;
        isEnd=false;
    }
};

class Trie{
    TrieNode *root;
    int numWords;

public:
    Trie(){
        root= new TrieNode('\0');
        numWords=0;
    }

    void addWordUtil(TrieNode* root,char *word){
        if(word[0]=='\0'){
            root->isEnd=true;
            return;
        }

        char ch=word[0];

        if(root->myMap.find(ch)==root->myMap.end()){
            TrieNode* temp=new TrieNode(ch);
            root->myMap[ch]=temp;
            root=temp;
        }
        else{
            TrieNode* temp=root->myMap[ch];
            root=temp;
        }
        addWordUtil(root,word+1);
    }

    void addWord(char *word){
        numWords++;
        addWordUtil(root,word);
    }

    bool findWord(char *word){
        TrieNode* temp=root;

        for(int i=0;word[i]!='\0';i++){

            if(temp->myMap.find(word[i])==temp->myMap.end())
                return false;
            else
                temp=temp->myMap[word[i]];
        }
        return true;
    }
};

int main(){

    char word[][100] = {"apple","mango","banana","as","a","no","not"};
    char search[][100] = {"ape","man","mango","no","noty","a"};

    Trie t;
    for(int i=0;i<7;i++){
        t.addWord(word[i]);
    }
    //Search for words
    for(int i=0;i<6;i++){
        if(t.findWord(search[i])==true){
            cout<<search[i]<<" exists in the document !"<<endl;
        }
    }
    return 0;
}

















