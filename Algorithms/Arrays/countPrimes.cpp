using namespace std;
#include<bits/stdc++.h>
int countPrimes(int n){
    int count = 0;
    vector<int> arr(n+1,1);
    arr[0]=0,arr[1]=0;
    for(int i = 2; i*i<=n; i++){
        if(arr[i])
            for( int j = i*i; j<=n; j+=i){
                if(arr[j]) arr[j]=0;
            }
    }
    for(int i = 2; i<=n; i++)
        if(arr[i])count++;
    
    return count;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    cout<<countPrimes(n);
    return 0;
}