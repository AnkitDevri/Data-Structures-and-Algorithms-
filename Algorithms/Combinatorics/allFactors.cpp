using namespace std;
#include<bits/stdc++.h>

int main(){
    int num,count;
    cin>>num;
    for(int i=1;i<=sqrt(num);i++){
    if(i*i==num)
     cout<<i<<" ";
     else if(num%i==0)
      cout<<i<<" "<<num/i<<" ";
 
    }
    

    getchar();
    return 0;
}