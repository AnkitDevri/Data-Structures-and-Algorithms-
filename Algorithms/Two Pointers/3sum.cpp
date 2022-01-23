using namespace std;                                        // Triplet sum should be zero
#include<bits/stdc++.h>
  vector<vector<int>> threeSum(vector<int>& nums){
        if(nums.size()<=2) return{};
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1])i++;
            int target = -1*(nums[i]);
            int p1 = i+1;
            int p2 = nums.size()-1;
            while(p1<p2){
                int sum = nums[p1]+nums[p2];
                if(sum==target) {
                    vector<int> temp = {nums[i],nums[p1],nums[p2]};
                    if(ans.size()>0){
                        bool found = false;
                        for(auto i : ans){
                            if(i==temp) {found=true; break;}
                        }
                        if(!found) ans.push_back(temp);
                    }
                    else ans.push_back(temp);
                }
                if(sum<target) p1++;
                else p2--;
            }
        }
        return ans;
    }

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int total_elements,element;
    cin>>total_elements;
    vector<int> arr(total_elements);
    
    for(int i=0;i<total_elements;i++){
        cin>>element;
        arr[i]=element;
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>> Solution=threeSum(arr);

    for(int i=0;i<Solution.size();i++){
        for(int j=0;j<Solution[i].size();j++){
            cout<<Solution[i][j]<<" ";
        }
        cout<<endl;
    }
    getchar();
    return 0;
}