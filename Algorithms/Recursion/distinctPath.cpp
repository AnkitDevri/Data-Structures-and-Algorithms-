using namespace std;
#include<bits/stdc++.h>
int paths=0;
int calclulatePaths(int i1,int j1,int i2,int j2){
   if(i1>i2)
    return 0;
   if(j1>j2)
    return 0;
   if(i1==i2 && j1==j2)
    return 1;
   else{
    
      return calclulatePaths(i1+1,j1,i2,j2)+calclulatePaths(i1,j1+1,i2,j2); 
   }
}
int main(){
    
    int i1,j1;
    cin>>i1>>j1;

    int i2,j2;
    cin>>i2>>j2;
    
    paths=calclulatePaths(i1,j1,i2,j2);
    cout<<paths;
    getchar();
    return 0;
}