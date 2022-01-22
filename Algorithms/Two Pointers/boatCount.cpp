using namespace std;
#include<bits/stdc++.h>
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count = 0;
        int p1 = 0,p2 = people.size()-1;
        while(p1<=p2){
            if(people[p2]+people[p1]>limit){
                p2--;
                count++;
            }
            else {
                p1++;
                p2--;
                count++;
            }
        }
        return count;
    }
int main(){
    int size;
    cin>>size;
    vector<int> peopleWeights(size,0);
    for(int i = 0; i < peopleWeights.size(); i++) cin>>peopleWeights[i];
    int limit;
    cin>>limit;
    cout<<numRescueBoats(peopleWeights,limit);
    return 0;
}