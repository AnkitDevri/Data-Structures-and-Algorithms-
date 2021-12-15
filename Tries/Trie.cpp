using namespace std;
#include <bits/stdc++.h>
class trieNode{
    public:
    int subStrings;
    vector <trieNode*> child; 
    bool stringEnds;

    trieNode(){
        subStrings = 0;
        child.assign(26,nullptr);
        stringEnds = false;
    }  
};

class trie{
    // private function acting as a helper function for some core functions
    int findStringStartingWith(trieNode* root, string& data, int pos){
        if(!root) 
            return 0;
        if(pos == data.size()) 
            return root->subStrings;
        return findStringStartingWith(root->child[data[pos]-'a'],data,pos+1);
    }
    // helper function to find full strings present in the trie
    bool isStringPresent(trieNode* root, string& data, int pos){
        if(!root) 
            return false;
        if(pos == data.size()) 
            return root->stringEnds;
        return isStringPresent(root->child[data[pos]-'a'],data,pos+1);
    }
    // helper function to delete in trie
    void deletion(trieNode* root,string& data,int pos,bool& found){
        if(!root) return;
        if(pos == data.size()){
            if(root->stringEnds) {
                found = true;
                root->subStrings--;
            }
            return;
        }
        deletion(root->child[data[pos]-'a'],data,pos+1,found);
        if(found) root->subStrings--;
        if((root->child[data[pos]-'a'])->subStrings == 0) {
            trieNode *temp = root->child[data[pos]-'a'];
            root->child[data[pos]-'a'] = nullptr;
            delete temp;
        }
    }
    public:
     trieNode* head;
     trie(){
         head = new trieNode();
     }
    
    // insert function not working correctly
    void push(trieNode* root,string& data){
        trieNode* temp = root;
        int pos = 0;

         if(!temp) temp = new trieNode();
         temp->subStrings++;

        while(pos < data.size()){
            if(!temp->child[data[pos]-'a'])
                temp->child[data[pos]-'a'] = new trieNode();
            temp = temp->child[data[pos]-'a'];
            temp->subStrings++;
            pos++;
        }
        temp->stringEnds = true;
    }
    

    // delete function to be implemented later
    void pop(trieNode* root,string& data){
        bool found = false;
        deletion(root,data,0,found);
    }

    // to find whether the given string is present in the trie
    bool find(trieNode* root,string& data){
       return isStringPresent(root,data,0);
    }

    // to find total strings starting with prefix
    int findPrefix(trieNode* root,string& data){
        return findStringStartingWith(root,data,0);
    }
};
int main(){
    trie obj;
    string input,prefix;
    cin>>input;
    obj.push(obj.head,input);
    cin>>prefix;
    //int val = obj.findPrefix(obj.head,prefix);
    //cout<<val;
    cout<<obj.find(obj.head,prefix);

    getchar();
    return 0;
}