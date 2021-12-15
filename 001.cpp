using namespace std;
#include<bits/stdc++.h>

int main(){
    int totalEntries;
    cin>>totalEntries;
    vector<int> nums;
    int entry;
    int answer = 0;
    for(int i = 0; i < totalEntries; i++) {
        cin>>entry;
        nums.push_back(entry);
    }
    for(int i = 0; i < totalEntries; i++)
        for(int j = i+1; j < totalEntries; j++)
             if(i*j == nums[i]*nums[j]) answer++;
        
    cout<<answer;
    return 0;

}