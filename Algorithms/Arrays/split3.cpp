using namespace std;
#include <bits/stdc++.h>
long long countSplits(vector<int>& arr){

    vector<long long> psum(arr.size(),0);
    psum[0]=arr[0];

    for(int i = 1; i<arr.size(); i++) 
        psum[i] = psum[i-1] + arr[i];

    long long sum = psum[psum.size()-1];
    if(sum%3!=0) return 0;

    long long  target = sum/3;
    long long cnt = 0;

    for( int i = 0; i<psum.size(); i++){
        if(psum[i]==target) psum[i]=1;
        else psum[i]=0;
    }
    //cout<<psum[0]<<" ";
    for(int i = 1; i<arr.size(); i++){
        psum[i] = psum[i-1] + psum[i];
     //   cout<<psum[i]<<" ";
    }
    //cout<<endl;
    vector<long long> ssum(arr.size(),0);
    ssum[arr.size()-1] = arr[arr.size()-1];
    
    //cout<<ssum[ssum.size()-1]<<" ";
    for(int i = arr.size()-2; i>=0; i--){
        ssum[i] = arr[i] + ssum[i+1];
     //   cout<<ssum[i]<<" ";
    }
    //cout<<endl;
    long long count = 0;
    for(int i = ssum.size()-1;i>=1;i--){
        if(ssum[i]==target){
            if(i>=2 && psum[i-1]==psum[i-2])
                count+=psum[i-1];
            else if(psum[i-1]>0) count+=psum[i-1]-1;
        }
    }
    return count;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    cout<<countSplits(arr);
    return 0;
}