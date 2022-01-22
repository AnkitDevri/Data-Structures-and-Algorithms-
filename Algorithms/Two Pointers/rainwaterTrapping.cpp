using namespace std;
#include<bits/stdc++.h>
 int trap(vector<int>& height) {
        int ans = 0;
        int p1 = 0, p2 = height.size()-1;
        int p1Max = 0,p2Max = 0;
        while(p1<p2){
        if(height[p1] < height[p2]) {
                p1Max = max(p1Max, height[p1]);
                ans += p1Max - height[p1];
                p1++;
            }
            else {
                p2Max = max(p2Max, height[p2]);
                ans += p2Max - height[p2];
                p2--;
            }
    }
        return ans;
    }
int main(){
    int size;
    cin>>size;
    vector<int> height(size,0);
    for(int i = 0; i < height.size(); i++) cin>>height[i];
    cout<<trap(height);
}