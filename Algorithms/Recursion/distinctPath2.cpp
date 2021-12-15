using namespace std;
#include<bits/stdc++.h>
void calculatePaths(int i1,int j1,int i2,int j2,int& count){
    if(i1>i2)
     return;
     if(j1>j2)
     return;
     if(i1==i2 && j1==j2)
     count+=1;

     calculatePaths(i1+1,j1,i2,j2,count);
     calculatePaths(i1,j1+1,i2,j2,count);
}
int main(){
    int i1,j1,i2,j2,count=0;
    cin>>i1>>j1>>i2>>j2;
    calculatePaths(i1,j1,i2,j2,count);
    cout<<count;
    getchar();
    return 0;
}