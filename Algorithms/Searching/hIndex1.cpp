using namespace std;
#include<bits/stdc++.h>
bool check (vector<int> nums,int idx){
    return nums[idx] >= nums.size() - idx;
}
int hIndex(vector<int>& citations,int start,int end) {
    int mid = (start+end)/2;
    if(check(citations,mid) && !check(citations,mid-1)) return citations.size()-mid;
    if(check(citations,mid) && check(citations,mid-1)) return hIndex(citations,start,mid-1);
    else return hIndex(citations,mid+1,end);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> citations(size+1);
    for(int i = 1; i < citations.size(); i++) cin>>citations[i];
    cout<<hIndex(citations,1,citations.size()-1);
    return 0;
}