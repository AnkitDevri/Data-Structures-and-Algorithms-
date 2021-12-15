using namespace std;
#include<bits/stdc++.h>

int getPower(int n, int p){
    if( p == 0) return 1;
    int power = n * getPower(n,p-1);
    return power;
    
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