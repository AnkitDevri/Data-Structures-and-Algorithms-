using namespace std;
#include <bits/stdc++.h>
 int countDiff(string s1, string s2) {
        int count = 0;
        vector<int> char_count(26,0);
        for (int i = 0; i < s1.length(); i++) char_count[s1[i] - 'a']++;
        for (int i = 0; i < s2.length(); i++) char_count[s2[i] - 'a']--;      
        for(int i = 0; i < 26; ++i)
            if(char_count[i] != 0) 
                count+=abs(char_count[i]);
        return count / 2;
}
vector<int> getDiff(vector<string>& first,vector<string>& second){
    vector<int> ans;
    for(int i = 0; i< first.size(); i++){
        if(first[i].length()==second[i].length()){
            int val = countDiff(first[i],second[i]);
            ans.push_back(val);
        }
        else ans.push_back(-1);
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<string> first;
    string inpt;
    for(int i = 0; i<n; i++){
        cin>>inpt;
        first.push_back(inpt);
    }
    cin>>n;
    vector<string> second;
    for(int i = 0; i<n; i++){
        cin>>inpt;
        second.push_back(inpt);
    }
    vector<int> ans = getDiff(first,second);
    for( auto i : ans) cout<<i<<endl;
    return 0;
}