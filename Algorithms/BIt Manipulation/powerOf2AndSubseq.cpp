using namespace std;
#include<bits/stdc++.h>
long long numberOfSubsequences(int N, long long A[]){
    int count = 0; 
    for(int i = 0 ; i < N; i++) {
        if(A[i]&(A[i]-1) == 0) count++;
    }
    return 1<<count -1;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    long long A[size];
    for(int i = 0 ; i < size ; i++){
        cin>>A[i];
    }
    cout<<numberOfSubsequences(size,A);
    return 0;
}