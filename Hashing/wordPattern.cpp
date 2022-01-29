using namespace std;
#include<bits/stdc++.h>
   bool wordPattern(string pattern, string s) {
        unordered_map<char,string> match;
        int idx = 0;
        int i = 0;
        while(i < s.size()){
            string temp;
            while(i<s.length() && s[i]!=' '){temp+=s[i];i++;}
              auto j = match.begin();
                while(j!=match.end()){
                    if(j->second==temp && j->first!=pattern[idx]) return false;
                    j++;
                }
            if(match.find(pattern[idx])==match.end()){
                match[pattern[idx]]=temp;
            }
            else{
                if(temp!=match[pattern[idx]]) return false;
            }
            idx++;
            i++;
        }
        if(idx<pattern.length()) return false;
        return true;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    string word,pattern;
    getline(cin,word);
    cin>>pattern;
    cout<<wordPattern(pattern,word);
    return 0;
}