using namespace std;
#include<bits/stdc++.h>
 string utl(string& s,int& idx){
        if(idx==s.length()) 
            return "";
        string temp="";
        int num = 0;
        int i = idx;
        string END="";
        
        while(isdigit(s[i])){
            num = num*10 +(s[i]-'0');
            i++;
        }

        char t = s[i];
        int j = i+1;

        for(j=i+1; s[j]!=']';j++){
            if(isdigit(s[j])){
                idx = j;
                temp.append(utl(s,idx));
            }
            temp+=s[j];
        }
        for(int k = 1; k<num; k++) 
            temp+=temp;

        if(j<s.length() && s[j]==']') 
            j++;

        while(j<s.length() && !isdigit(s[j])){
            END+=s[j];
            j++;
        }
        idx=j;
        temp+=END;
        return temp;   
    }
    string decodeString(string s) {
        string ans="";
        int idx=0;
        while(idx<s.length()) ans+=utl(s,idx);
        return ans;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    cout<<decodeString(s);
    return 0;
}