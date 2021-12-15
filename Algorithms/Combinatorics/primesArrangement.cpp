#include<bits/stdc++.h>
using namespace std;
 long long m=1e9+7;
 vector<bool>tell(101,1);
int getprimes(int n){
    int count=0;
   for(int i=1;i<=n;i++)
    if(tell[i])
     count++;
 return count;
}
 
long long factorial(int n)
{
    return (n==1 || n==0) ? 1: (n%m * factorial(n - 1)%m)%m;
}
int main(){

     tell[0]=tell[1]=false;
    for(int i=2;i*i<=100;i++)
     if(tell[i])
     for(int j=i;j*i<=100;j++)
       tell[i*j]=false;

    int n;
    cin>>n;
    int primes=getprimes(n);
    int nonPrimes=n-primes;
    cout<<((factorial(primes)%m)*(factorial(nonPrimes)%m))%m;
    getchar();
    return 0;
}