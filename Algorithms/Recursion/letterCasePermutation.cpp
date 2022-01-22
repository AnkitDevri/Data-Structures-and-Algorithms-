  #include<bits/stdc++.h>
  using namespace std;
  void utl(vector<string>& ans,string& s,string& t,int idx){
        if(idx==s.size()){
            ans.push_back(t);
            return;
        }
        t+=s[idx];
        utl(ans,s,t,idx+1);
        t.pop_back();
        if(!isdigit(s[idx]))
        {
            char temp = s[idx];
            if(isupper(temp)) t+=tolower(temp);  
            else t+=toupper(temp);
             utl(ans,s,t,idx+1);
             t.pop_back();
        }
       

    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string t;
        utl(ans,s,t,0);
        return ans;
    }

 int main(){
     string s;
     cin>>s;
     vector<string> perms = letterCasePermutation(s);
     for(auto i : perms) cout<<i<<" ";
     return 0;
 }