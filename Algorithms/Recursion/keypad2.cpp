using namespace std;
#include <bits/stdc++.h>
void getCombinations(vector<vector<char>>& keypad,string& str,int idx,vector<string>& allCombs,string& temp){
    if(temp.size() == str.size()){
        allCombs.push_back(temp);
        return;
    }
    for(int i = 0; i < keypad[str[idx]-'0'].size(); i++){
        temp.push_back(keypad[str[idx]-'0'][i]);
        getCombinations(keypad,str,idx+1,allCombs,temp);
        temp.pop_back();
    }
}
void initKeypad(vector<vector<char>>& keypad){
    keypad[2] = {'a','b','c'};
    keypad[3] = {'d','e','f'};
    keypad[4] = {'g','h','i'};
    keypad[5] = {'j','k','l'};
    keypad[6] = {'m','n','o'};
    keypad[7] = {'p','q','r','s'};
    keypad[8] = {'t','u','v'};
    keypad[9] = {'w','x','y','z'};
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    string str;
    cin>>str;
    vector<vector<char>> keypad(10,vector<char>(3));
    initKeypad(keypad);
    vector<string> allCombs;
    string temp;
    getCombinations(keypad,str,0,allCombs,temp);
    for(auto i : allCombs) cout<<i<<endl;
    return 0;
}