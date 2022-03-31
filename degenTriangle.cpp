using namespace std;
#include <bits/stdc++.h>
vector<bool> getResults(vector<int>& a, vector<int>& b, vector<int>& c){
    vector<bool> ans(a.size(),false);
    for(int i = 0; i<a.size(); i++){
        if(a[i]+b[i]>c[i] && b[i]+c[i]>a[i] && c[i]+a[i]>b[i]) 
            ans[i]=true;
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
    vector<int> a(n,0);
    vector<int> b(n,0);
    vector<int> c(n,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    cin>>n;
    for(int i = 0; i<n; i++) cin>>b[i];
    cin>>n;
    for(int i = 0; i<n; i++) cin>>c[i];
    vector<bool> ans = getResults(a,b,c);
    for(int i = 0; i<n; i++){
        if(ans[i]) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}