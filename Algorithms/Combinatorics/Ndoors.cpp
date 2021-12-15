using namespace std;
#include<bits/stdc++.h>

int main(){
   int size;
   cin>>size;
   bool doors[size]={false};
   for(int i=1;i<size+1;i++)
    {
        int val=sqrt(i);
        if(val*val==i)
         doors[i-1]=!doors[i-1];
    }
    for(int i=0;i<size;i++)
     cout<<doors[i]<<" ";
  getchar();
  return 0;
}