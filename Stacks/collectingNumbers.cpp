using namespace std;
#include <bits/stdc++.h>

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int n,a,ans=1;
    cin>>n;
    int pos[n+1];

    for(int i=1;i<=n;i++)
        cin>>a,pos[a]=i;

    for(int i=1;i<n;i++)
        if(pos[i+1]<pos[i])
            ans++;
            
    cout<<ans<<endl;
}