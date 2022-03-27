using namespace std;
#include <bits/stdc++.h>
  int cnt = 0;
    string ans="";
    void getLexicoPerms(string& str,int& k,int idx){
        if(idx==str.size()-1){
            cnt++;
            if(cnt==k) ans=str;
            return;
        }
        for(int i = idx; i<str.length(); i++){
            char c = str[i];
            for(int j = i; j>idx; j--) str[j]=str[j-1];

            str[idx]=c;

            getLexicoPerms(str,k,idx+1);

            c=str[idx];
            for(int j = idx; j<i; j++) str[j]=str[j+1];

            str[i]=c;
        }
    }
    string getPermutation(int n, int k) {
        string str="";
        for(int i = 1; i<=n; i++) str+=to_string(i);
        getLexicoPerms(str,k,0);
        return ans;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    cout<<getPermutation(n,k);
    return 0;
}