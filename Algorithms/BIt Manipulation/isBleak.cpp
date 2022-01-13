using namespace std;
#include<bits/stdc++.h>
int CountSetBit(int n){
    int count = 0;
    if(n==0) return count;
    while(n){
        count++;
        n=n&(n-1);
    }
    return count;
}
int isBleak(int n){
    if(n==1) return 1;
    for(int i = n-32; i < n; i++){
        if(i<0) i=0;
        if(i + CountSetBit(i) == n) return 0;
    }
    return 1;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    cout<<isBleak(n);
    return 0;
}