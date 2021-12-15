using namespace std;
#include<bits/stdc++.h>
int main(){
    long long int n,i;
    cin>>n;
    if(n%2!=0)
    cout<<n*(n-1)*(n-2);
    else
    {
     for( i=n-2;i>1;i--)
       if(__gcd(n,i)==1)
          break;
        cout<<n*(n-1)*i;
    }
    return 0;
}