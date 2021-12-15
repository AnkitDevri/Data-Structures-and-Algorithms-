using namespace std;
#include<bits/stdc++.h>
bool compare(pair<char,int> p1,pair<char,int> p2){
    if(p1.second<p2.second) return true;
    else return false;
}
int main(){
    string order,s;
    cin>>order>>s;
    vector<int> rank(26,-1);
    vector<pair<char,int>> to_test;
    for(int idx=0;idx<order.length();idx++){
        rank[order[idx]-'a']=idx;
    }
    for(int idx=0;idx<s.length();idx++){
        to_test.push_back(make_pair(s[idx],rank[s[idx]-'a']));
    }
    sort(to_test.begin(),to_test.end(),compare);
    string answer ="";
    for(int idx=0;idx<s.size();idx++){
        answer+=to_test[idx].first;
    }
    cout<<answer;
    getchar();
    return 0;
}