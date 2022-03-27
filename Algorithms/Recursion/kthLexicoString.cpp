using namespace std;
#include <bits/stdc++.h>
    int cnt = 0;
    string ans;
    void getStrings(vector<string>& choices,string temp,int& n,int& k,char c){
        if(temp.length()==n){
            cnt++;
            if(cnt==k) ans=temp;
            return;
        }
       
        string s = choices[c-'a'];
        for(int i = 0; i<s.length(); i++){
            temp+=s[i];
            getStrings(choices,temp,n,k,s[i]);
            temp.pop_back();
        } 
    }
    string getHappyString(int n, int k) {
        vector<string> choices ={"bc","ac","ab"};
        string temp="a";
        getStrings(choices,temp,n,k,'a');
        temp="b";
        getStrings(choices,temp,n,k,'b');
        temp="c";
        getStrings(choices,temp,n,k,'c');
        
        return ans;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    cout<<getHappyString(n,k)<<endl; 
    return 0;
}