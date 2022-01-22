using namespace std;
#include<bits/stdc++.h>
string digiSum(string n,int& k){
    if(k==0){
     return n;
    }
      int num=0;
      for(int i=0;i<n.length();i++)
         num+=int(n[i]-'0');
         k--;
    return digiSum(to_string(num),k);
}
//new approach
int utl(string s){
    if(s.length()==1) return s[0]-'0';
    long long sum = 0;
    for(int i = 0; i<s.length(); i++){
        sum = (s[i]-'0')+sum;
    }
    return utl(to_string(sum));
}
int superDigit(string n, int k) {
  long long sum  = 0;
  for(int i = 0; i < n.length(); i++){
      sum = (n[i]-'0')+sum;
  }
  sum*=k;
  string s = to_string(sum);
  return utl(s);
}


int main(){
    int k;
    string str;
    string g;
    cin>>g>>k;
    str=g;
    for(int i=1;i<k;i++)
       g+=str;
    cout<<digiSum(g,k);
    cout<<superDigit(g,k);
    getchar();
    return 0;
}