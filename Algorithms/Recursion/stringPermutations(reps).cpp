using namespace std;
#include<bits/stdc++.h>
 void permutations(vector<string>& perms,string& a,int index){
   if(index==a.size()-1){
       perms.push_back(a);
       return;
   }
     vector<int> freq(26,0);
   for(int i=index;i<a.size();i++){
     if(freq[a[i]-'a']==0){
      swap(a[index],a[i]);
      permutations(perms,a,index+1);
      swap(a[index],a[i]);
     }
       freq[a[i]-'a']++;
   }
 }
int main(){
    string a;
    cin>>a;
    vector<string> perms;
    permutations(perms,a,0);
    for(auto x : perms)
      cout<<x<<endl;
    getchar();
    return 0;
}