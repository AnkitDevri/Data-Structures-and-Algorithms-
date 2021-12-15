using namespace std;
#include<bits/stdc++.h>

int exp(int& n,int k){
    if(k==0)
     return 1;
    int x=exp(n,k/3);
    if(k%3==0)
    return x*x*x;
    else if(x%3==1)
    return x*x*x*n;
    else
     return x*x*x*n*n;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<exp(n,k);
    getchar();
    return 0;
}