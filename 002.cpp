using namespace std;
#include<bits/stdc++.h>

int minTime(vector<int>& nums,int gold){
    int time = 0;
 
    while (true){
        int items = 0;
        for (int i = 0; i < nums.size(); i++)
            items += (time / nums[i]);
            if (items >= gold)
                return time;
        time++; 
    }
    
}

int main(){
    int totalMachines;
    vector<int> timeLimits;
    int gold;

    cin>>totalMachines;
    cin>>gold;
    int timeValue;
    for(int i = 0; i < totalMachines; i++){
        cin>>timeValue;
        timeLimits.push_back(timeValue);
    }

    cout<<minTime(timeLimits,gold);
    return 0;
}
