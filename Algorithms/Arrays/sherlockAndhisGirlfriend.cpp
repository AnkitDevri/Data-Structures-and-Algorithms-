using namespace std;
#include<bits/stdc++.h>
vector<int> getColors(int n){
    vector<int> ans(n,1);
    for(int i = 2; i*i<n+2; i++){
        if(ans[i-2]==1){
            for(int j = 2*i; j<n+2; j+=i){
                if(ans[j-2]==1) ans[j-2]++;
            }
        }
    }

    return ans;
}
int main(){ 
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<int> ans = getColors(n);
    if(n<=2) cout<<1<<endl;
    else cout<<2<<endl;
    for(int i = 0; i < ans.size(); i++) 
        cout<<ans[i]<<" ";
    return 0;
}