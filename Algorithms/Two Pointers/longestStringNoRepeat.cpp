using namespace std;
#include <bits/stdc++.h>
   int lengthOfLongestSubstring(string s) {
      if(s.length()==0) return 0;
      if(s.length()==1) return 1;
      vector<int>frq(256,0);
      int ans = 0;
      int p1 = 0, p2 = 1;
      frq[s[p1]]++;
      frq[s[p2]]++;
      while(p2<s.length()){
          while(frq[s[p2]]>1){
              frq[s[p1]]--;
              p1++; 
          }
          p2++;
          frq[s[p2]]++;
          ans = max(ans,p2-p1);
      }
      return ans;
    }
int main(){
    string s;
    getline(cin,s);
    cout<<lengthOfLongestSubstring(s);
    return 0;
}