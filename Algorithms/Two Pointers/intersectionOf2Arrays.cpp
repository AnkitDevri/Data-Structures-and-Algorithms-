using namespace std;
#include <bits/stdc++.h>
vector<int> intersection(vector<int>& nums1,vector<int>& nums2){
    int p1=0,p2=0;
    vector<int> ans;
    while(p1 < nums1.size() && p2 < nums2.size()){
        if(nums1[p1]==nums2[p2]){
            ans.push_back(nums1[p1]);
            while(nums1[p1]==nums2[p2])p1++;  
        }
        else if(nums1[p1]>nums2[p2]) p2++;
        else p1++;
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int size1,size2;
    cin>>size1>>size2;

    vector<int>nums1(size1,0);
    vector<int>nums2(size2,0);

    for(int i = 0 ; i < nums1.size(); i++) cin>>nums1[i];
    for(int i = 0 ; i < nums2.size(); i++) cin>>nums2[i];

    sort(nums2.begin(),nums2.end());
    sort(nums1.begin(),nums1.end());

    vector<int> intersect = intersection(nums1,nums2);

    for(auto i : intersect) cout<<i<<" ";
    return 0;
}