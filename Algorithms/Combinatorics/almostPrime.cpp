using namespace std;
#include<bits/stdc++.h>
 vector<int> sieve;
 void createSieve(int n){
   vector<bool> tell(n,true);
   tell[0]=tell[1]=false;
   for(int i=2;i*i<=n;i++){
     if(tell[i])
     for(int j=i*i;j<=n;j+=i)
       tell[j]=false;
   }
   for(int i=2;i<=n;i++)
    if(tell[i])
     sieve.push_back(i);
 }

  int getAlmostPrimes(int n){
      int count=0;
      if(n==1)
       return count;
    for(int i=1;i<=n;i++){
        int pCount=0;
        int temp=i;
         for(int j=0;sieve[j]*sieve[j]<=temp;j++){
          if(temp%sieve[j]==0)
             pCount++;
          while(temp%sieve[j]==0)
            temp=temp/sieve[j];
         }
         if(temp>1)
          pCount++;
        if(pCount>=2)
        count++;
    }
    return count;
  }
int main(){
    int n;
    cin>>n;
    createSieve(n);
    cout<<getAlmostPrimes(n);
    getchar();
    return 0;
}