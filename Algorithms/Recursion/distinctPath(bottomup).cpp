#include<bits/stdc++.h>
using namespace std;
int calcPaths(int i1,int j1){
    if(i1<0)
     return 0;
     if(j1<0)
     return 0;
     if(i1==0 && j1==0)
     return 1;
    
   return calcPaths(i1-1,j1)+calcPaths(i1,j1-1);
}
int main(){
    int i1,j1;
    cin>>i1>>j1;
    cout<<calcPaths(i1,j1);
    getchar();
    return 0;
}