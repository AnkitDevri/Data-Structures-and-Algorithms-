#include<bits/stdc++.h>
using namespace std;
 void computeJwellery(int altSieve[],int n){
     int count=1;
     altSieve[0]=altSieve[1]=0;
     int i=0,j=0;
     for(i=2;i*i<=n;i++)
      if(altSieve[i]==1){
        for(j=i*i;j<=n;j+=i)
         altSieve[j]=altSieve[j]+count;
         count++;
      }
     cout << count<<endl;
     for(int i=2;i<=n;i++)
     cout<<altSieve[i]<<" ";
 }
int main(){
    int n;
    cin>>n;
    int altSieve[n+2];
    std::fill_n (altSieve, n+2, 1);
    computeJwellery(altSieve,n+1);
    getchar();
    return 0;
}