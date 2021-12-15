using namespace std;
#include<bits/stdc++.h>
void balanceBraces(vector<string>& P,int O,int C,char sample[],int index,int& n){
  if(index==2*n){
    
    int i;
    string s = "";
    for (i = 0; i < 2*n; i++) {
        s = s + sample[i];
    }
    P.push_back(s);
    return;
  }
  if(O==C){
      sample[index]='(';
      balanceBraces(P,O+1,C,sample,index+1,n);
  }
  
    else if(O>C){
    if(O==n){
      sample[index]=')';
      balanceBraces(P,O,C+1,sample,index+1,n);
  }
     else{
      sample[index]='(';
      balanceBraces(P,O+1,C,sample,index+1,n);
      sample[index]=')';
      balanceBraces(P,O,C+1,sample,index+1,n);
  }
 }
 
}
int main(){
    int n;
    cin>>n;
    char sample[2*n];
    vector<string> P;
    balanceBraces(P,0,0,sample,0,n);
    for(auto x: P)
    cout<<x<<"\n";
    getchar();
    return 0;
}