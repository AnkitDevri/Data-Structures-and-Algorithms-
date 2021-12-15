using namespace std;
#include<bits/stdc++.h>
    vector<int> primes(){
        vector<int> sieve;
        vector<bool> tell(1000001,true);
        tell[0]=tell[1]=false;
        for(int i=2;i*i<=1000000;i++)
         if(tell[i])
          for(int j=i;i*j<=1000000;j++)
            tell[i*j]=false;

         for(int i=2;i<tell.size();i++)
          if(tell[i])
          sieve.push_back(i);
        return sieve;
    }
    void getPrimes(int left,int right,vector<int> sieve){
        vector<bool>tell(right-left+1,true);
        for(int i=0;i<sieve.size();i++){
            int k=ceil((left*1.0)/sieve[i]);
            for(int j=max(k,2);sieve[i]*j<=right;j++)
              tell[sieve[i]*j-left]=false;
        }
        for(int i=0;i<tell.size();i++)
        if(tell[i])
        cout<<left+i<<" ";
     }
    
int main(){
    int left,right;
    cin>>left>>right;
    getPrimes(left,right,primes());
    getchar();
    return 0;
}