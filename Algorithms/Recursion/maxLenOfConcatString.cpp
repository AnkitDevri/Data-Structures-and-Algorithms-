using namespace std;
#include <bits/stdc++.h>
  int maxlen = 0;
    int getBit(string &s){
        int ans = 0;
        for(int i = 0; i<s.length(); i++){
            int mask = 1<<(s[i]-'a');
            if((mask&ans) != 0 ) 
                return -1;
            ans+=mask;
        }
        return ans;
    }
    void helper(vector<string>& arr,int &ans,int& freq,int idx){
        maxlen = max(ans,maxlen);
        if(idx==arr.size()) return;
            int bit = getBit(arr[idx]);
            if(bit!=-1){
                if((freq&bit) == 0){
                    freq+=bit;
                    ans+=arr[idx].length();
                    helper(arr,ans,freq,idx+1);
                    ans-=arr[idx].length();
                    freq-=bit;
                }
            }
            helper(arr,ans,freq,idx+1);
        
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        int freq = 0;
        helper(arr,ans,freq,0);
        return maxlen;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<string> str(size);
    for(int i = 0; i < size; i++)
        cin>>str[i];
    cout<<maxLength(str);
    return 0;
}