using namespace std;
#include<bits/stdc++.h>
void balanceBraces(vector<string>& P,int O,int C,int T,int F,char sample[],int index,int& n,int& m){
  if(index==2*n){
    
    int i;
    string s = "";
    for (i = 0; i < 2*n; i++) {
        s = s + sample[i];
    }
    P.push_back(s);
    return;
  }
   if(T==F){
      sample[index]='{';
      balanceBraces(P,O,C,T+1,F,sample,index+1,n,m);
  }
  
  if(O==C){
      sample[index]='(';
      balanceBraces(P,O+1,C,T,F,sample,index+1,n,m);
   }
  
  
    else if(O>C){
    if(O==n){
      sample[index]=')';
      balanceBraces(P,O,C+1,T,F,sample,index+1,n,m);
  }
     else{
      sample[index]='(';
      balanceBraces(P,O+1,C,T,F,sample,index+1,n,m);
      sample[index]=')';
      balanceBraces(P,O,C+1,T,F,sample,index+1,n,m);
  }
 }
 
}
int main(){
    int n,m;
    cin>>n>>m;
    char sample[2*n+2*m];
    vector<string> P;
    balanceBraces(P,0,0,0,0,sample,0,n,m);
    for(auto x: P)
    cout<<x<<"\n";
    getchar();
    return 0;
}