using namespace std;
#include<bits/stdc++.h>

int getfact(int n){
    if(n == 0) return 1;
    int answer = getfact(n-1) * n;
    return answer;
    
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    cout<<getfact(n);
    return 0;
}