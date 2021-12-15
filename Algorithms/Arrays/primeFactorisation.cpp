using namespace std;
#include<bits/stdc++.h>
  void primeFactorisation(int n){
      
    for(int i=2;i*i<=n;i++){
        if(n==1)
         break;
                                                                    //There can only be one prime number to the right of the square root of the number
                                                                    //The rest of the primes are to the left of the square root
        if(n%i!=0)
        continue;

        while(n%i==0){
        cout<<i<<" ";
        n=n/i;
     }
      if(n!=1)
      cout<<n;
    }
     
  }
int main(){
    int n;
    cin>>n;
    primeFactorisation(n);
    getchar();
    return 0;
}