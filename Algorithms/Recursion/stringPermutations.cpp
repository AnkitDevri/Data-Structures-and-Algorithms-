using namespace std;
#include<bits/stdc++.h>
 void permutations(vector<string>& perms,string& a,int index){
   if(index==a.size()-1){
       perms.push_back(a);
       return;
   }
   for(int i=index;i<a.size();i++){
      swap(a[index],a[i]);
      permutations(perms,a,index+1);
      swap(a[index],a[i]);
   }
 }
int main(){
   #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    string a;
    cin>>a;
    vector<string> perms;
    permutations(perms,a,0);
    for(auto x : perms)
      cout<<x<<endl;
    getchar();
    return 0;
}