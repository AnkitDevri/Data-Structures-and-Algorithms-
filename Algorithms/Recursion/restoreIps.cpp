using namespace std;
#include <bits/stdc++.h>
 void utl(vector<string>& ips,string& s,string &temp,int idx,int cnt){
        if(cnt==4 && s.length()-idx>0) 
            return;

        if(cnt==4 && s.length()-idx==0){
            temp.pop_back();
            //cout<<temp<<endl;
            ips.push_back(temp);
            temp.push_back('.');
            return;
        }
        if(idx<s.length()){
            temp+=s[idx];
            temp+='.';
            utl(ips,s,temp,idx+1,cnt+1);
            temp.pop_back();
            temp.pop_back();
        }
        
        if(s[idx]!='0' && idx+1<s.length()){
            temp+=s[idx];
            temp+=s[idx+1];
            temp+='.';
            utl(ips,s,temp,idx+2,cnt+1);
            temp.pop_back();
            temp.pop_back();
            temp.pop_back();
        }
        
        if(s[idx]!='0' && idx+2<s.length()){
            string k = s.substr(idx,3);
            if(k<="255"){
                temp+=s[idx];
                temp+=s[idx+1];
                temp+=s[idx+2];
                temp+='.';
                utl(ips,s,temp,idx+3,cnt+1);
                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        string temp;
        utl(ips,s,temp,0,0);
        return ips;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    vector<string> ans = restoreIpAddresses(s);
    for(auto i : ans) cout<<i<<endl;
    return 0;
}