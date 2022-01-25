using namespace std;
#include<bits/stdc++.h>
//not correct approach 
int getMaxPerimeter(vector<int>& sides){
    int ans = 0;
    sort(sides.begin(), sides.end());
    int left = 2, right = sides.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(sides[mid-1]+sides[mid-2]>sides[mid]){
            ans = max(ans,sides[mid]+sides[mid-1]+sides[mid-2]);
            left = mid+1;
        }
        else right = mid-1;
    }
    return ans;
}
//correct approach
int largestPerimeter(vector<int>& sides) {
    int ans = 0;
    sort(sides.begin(), sides.end());
    for(int i = sides.size()-1; i > 1; i--){
        if(sides[i-1]+sides[i-2]>sides[i]) {
            ans = sides[i]+sides[i-1]+sides[i-2];
            break;
        }
    }
    return ans;
    }
int main(){
    #ifndef ONILINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> sides(size,0);
    for(int i = 0 ; i < sides.size(); i++) cin>>sides[i];
    cout<<getMaxPerimeter(sides);
    return 0;
}