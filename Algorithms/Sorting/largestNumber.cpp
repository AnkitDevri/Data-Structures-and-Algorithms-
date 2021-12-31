using namespace std;
#include <bits/stdc++.h>
bool compare(int a, int b){
        string A = to_string(a);
        string B = to_string(b);
        return A+B>B+A;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> arr(size,0);
    for(int i = 0; i < arr.size(); i++) cin>>arr[i];
    sort(arr.begin(),arr.end(),compare);
    for(auto i : arr)cout<<i;
    return 0;
}
