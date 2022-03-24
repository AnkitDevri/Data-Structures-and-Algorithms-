using namespace std;
#include <bits/stdc++.h>

void smallestNumber(long long& ans,vector<long long>& nums,string& s){
    if(s.length()==0){
        for(auto i : nums){
            if(i!=-1) ans=min(ans,i);
        }
        return;
    }
    for(int i = 0; i<nums.size()-1; i++){
        if(nums[i]==-1) continue;
        for(int j = i+1; j<nums.size(); j++){
            if(nums[j]==-1) continue;

            long long val1 = nums[i];
            long long val2 = nums[j];
            char c = s.back();

            if(c=='*') nums[j]*=nums[i];
            else nums[j]+=nums[i];
            nums[i]=-1;
            s.pop_back();
            
            smallestNumber(ans,nums,s);
            nums[i]=val1;
            nums[j]=val2;
            s+=c;
        }
    
    }
   
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    vector<long long> nums(4,0);
    for(int i = 0; i<4; i++)
        cin>>nums[i];

    string s="";
    char c;
    for(int i = 0; i<3; i++){
        cin>>c;
        s+=c;
    }
    //sort(nums.begin(),nums.end(),greater<>());
    long long ans = LLONG_MAX;
    reverse(s.begin(),s.end());
    smallestNumber(ans,nums,s);
    cout<<ans;
    return 0;
}