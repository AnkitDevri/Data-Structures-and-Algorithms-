using namespace std;
#include <bits/stdc++.h>
int search(vector<int>& versions, int start, int end){
    int mid = (start + end)/2;
    if(versions[mid]){
        if(!versions[mid-1]) return mid;
    }
    if(versions[mid]) return search(versions,start,mid-1);
    else return search(versions,mid+1,end);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<int> versions(n+1);
    for( int i = 1; i < versions.size(); i++) cin>>versions[i];
    cout<<search(versions,1,n);
    return 0;
}