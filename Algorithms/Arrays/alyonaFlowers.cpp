using namespace std;
#include<bits/stdc++.h>

int getMaxHappiness(vector<vector<int>>& subarrayRanges, vector<int>& flowerMoods){
    int answer = 0;
    vector<int> preSum(flowerMoods.size(),0);
    preSum[0] = flowerMoods[0];
    for(int i = 1; i < flowerMoods.size();i++) 
        preSum[i] = preSum[i-1] + flowerMoods[i];
    
    int subarraySum = 0;
    int leftSum ,rightSum = 0;
    for(int i = 0; i < subarrayRanges.size(); i++){
        leftSum = 0;
        if(subarrayRanges[i][0] != 1 ) leftSum = preSum[subarrayRanges[i][0] - 2];
        rightSum = preSum[subarrayRanges[i][1] - 1];

        subarraySum  = rightSum - leftSum;
        if( subarraySum > 0) answer+=subarraySum;
    }

    return answer;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int totalFlowers,momSuggestion;
    cin>>totalFlowers;
    cin>>momSuggestion;

    vector<int> flowerMoods;
    int mood;
    for(int i = 0; i < totalFlowers; i++) {
        cin>>mood;
        flowerMoods.push_back(mood);
    }

    vector<vector<int>> subarrayRanges;
    vector<int> range(2,0);
    int left, right;
    for(int i = 0; i < momSuggestion; i++){
        cin>>left;
        cin>>right;
        range[0] = left;
        range[1] = right;
        subarrayRanges.push_back(range);
    }

    cout<<getMaxHappiness(subarrayRanges,flowerMoods);
    
    return 0;
}