using namespace std;
#include<bits/stdc++.h>

void printfunc(int n){
    if(n == 0) return;
    cout<<n<<endl;
    printfunc(n-1);
    cout<<n<<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    printfunc(n);
    return 0;
}