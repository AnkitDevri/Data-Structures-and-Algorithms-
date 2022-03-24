using namespace std;
#include <bits/stdc++.h>
string compute(long long n){
   if(n==0) 
    return "0";
   if(n==1) 
    return "1";

   string num;
   num = compute(n/2);
   int mod = n%2;
   
   string v;
   v+=num;
   v+=char(mod);
   v+=num;

    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    long long n;
    cin>>n;
    string v;
    long long l,r;
    v=compute(n);
    string ans;
    ans+=v;
    ans+=char(n%2);
    ans+=v;
    cin>>l>>r;
    l--;r--;
    int count = 0;
    for(int i = l; i<=r; i++){
        if(ans[i]) count++;
    }
    cout<<count;
    return 0;
}