using namespace std;
#include <bits/stdc++.h>
int TeamDiff(vector<int>& nums){
    int p1 = 0,p2 = nums.size()-1;
    int t1 = 0, t2 = 0;
    bool c1 = true;
    while(p1<=p2){
        int toadd = 0;
        if(nums[p1]>nums[p2]){
            bool lNeg = false;
            while(!lNeg && p1<p2 && nums[p1]>=nums[p2]){
                if(nums[p1]<0) lNeg=true;
                toadd+=nums[p1];
                p1++;
            }
        }
       /* else if(nums[p1]==nums[p2]){
            int q1 = p1+1, q2 = p2-1;
            while( q1 < q2 && nums[q1]>nums[q2]){

            }

        }*/
        else {
            bool lNeg = false;
            while(!lNeg && p1<p2 && nums[p2]>=nums[p1]){
                if(nums[p2]<0) lNeg=true;
                toadd+=nums[p2];
                p2--;
            }
        }
        if(p1==p2) {toadd=nums[p1];p1++;}
        if(c1) t1+=toadd;
        else t2+=toadd;
        c1=!c1;
    }
    return t1-t2;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> arr(size,0);
    for(int i = 0; i<arr.size(); i++){
        cin>>arr[i];
    }
    cout<<TeamDiff(arr);

    return 0;
}