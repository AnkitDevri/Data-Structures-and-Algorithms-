#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,k,l,t,n,ans;
    while(cin>>n)
    {
        if(n==1)
            ans=1;
        else if(n==2)
            ans=2;
        else if(n==3)
            ans=6;
        else if(n%2==0)
        {
            if(n%3==0)
                ans=(n-1)*(n-2)*(n-3);
            else
                ans=n*(n-1)*(n-3);
        }
        else
            ans=n*(n-1)*(n-2);
        cout<<ans<<endl;
    }
    return 0;
}
/*
using namespace std;
#include <bits/stdc++.h>
long maxL(long a,long b){
    if(a>b) return a;
    return b;
}
long getMaxLCM(int n){
    if(n==1) 
        return 1;

    long mul = n*(n-1);
    long ans  = mul;

    for(int i = n-2; i>=1; i--){
        //if(num%i==0) continue; 
        if(__gcd(n,i)==1 && __gcd(i,n-1)==1){
             mul*=i;
             ans=mul;
             break;
        }
    }

    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    cout<<getMaxLCM(n);
    return 0;
}
*/