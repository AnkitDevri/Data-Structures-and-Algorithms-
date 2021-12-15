using namespace std;
#include<bits/stdc++.h>
typedef long long int ll;
 int gcd(int a,int b){
   if(a==0 || b==0)
     return 0;
     
         if(a%b==0)
         return b;
         else
          return(b,a%b);
     
 }
int lcm(int a, int b){
    if(a==0 || b==0)
     return 0;
  else
  return (a*b)/gcd(a,b);
}
string result(ll n,int a, int b,ll k){
   if((n/a)+(n/b)-2*(n/lcm(a,b))<k)
     return "Lose";
     else
     return "Win";
}
int main(){
    int test,a,b;
    ll k,n;
    cin>>test;
    for(int i=0;i<test;i++)
    cin>>n>>a>>b>>k;
    for(int i=0;i<test;i++)
     cout<<result(n,a,b,k)<<endl;
    return 0;
}