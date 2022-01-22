#include<bits/stdc++.h>
using namespace std;
    int maxArea(vector<int>& height) {
        int ans = 0;
        int lmax = height[0],rmax = height[height.size()-1];
        int p1 = 0, p2 = height.size()-1;
        ans = min(height[p1],height[p2])*(p2-p1);
        while(p1<p2){
           if(height[p1]<height[p2]){
               p1++;
               ans = max(ans,min(height[p1],height[p2])*(p2-p1));
           }
            else if(height[p2]<height[p1]){
                p2--;
                ans = max(ans,min(height[p1],height[p2])*(p2-p1));
            }
            else{
                p1++;
                p2--;
                ans = max(ans,min(height[p1],height[p2])*(p2-p1));
            }
        }
        return ans;
    }
int main(){
    int size;
    cin>>size;
    vector<int> height(size,0);
    for(int i = 0; i < height.size(); i++)cin>>height[i];
    cout<<maxArea(height);
    return 0;
}