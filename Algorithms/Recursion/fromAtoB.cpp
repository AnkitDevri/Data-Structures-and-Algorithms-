using namespace std;
#include<bits/stdc++.h>
bool task(vector<long long>& path,long long  a, long long& b){
 if(a>b)
  return false;
 if(a==b){
    path.push_back(b);
    return true;
 }
  if(task(path,(a*10)+1,b)){
     path.push_back(a);
     return true;
  }
  if(task(path,2*a,b)){
     path.push_back(a);
     return true;
  }
    
  return false;
  
}
int main(){
    vector<long long> path;
    long long a,b;
    cin>>a>>b;
    if(task(path,a,b)){
     reverse(path.begin(),path.end());
     cout<<"YES\n";
     cout<<path.size()<<"\n";
     for(auto i : path)
     cout<<i<<" ";
    }
    else
    cout<<"NO";
    
    getchar();
    return 0;
}