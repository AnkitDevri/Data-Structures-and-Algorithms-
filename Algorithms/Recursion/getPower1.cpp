using namespace std;
#include<bits/stdc++.h>

long long getPower(int n, int p){
    if( p == 0 ) return 1;

    long long halfPower = getPower(n,p/2);
    long long fullPower = halfPower*halfPower;
    
    if( p%2 == 1) return fullPower*n;
    return fullPower;
    
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int n,p;
    cin>>n>>p;
    cout<<getPower(n,p);
    return 0;
}