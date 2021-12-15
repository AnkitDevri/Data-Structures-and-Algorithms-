using namespace std;
#include <bits/stdc++.h>
bool check ( unordered_map <string,int>& permanent, unordered_map<string,int>& changing, vector <string>& words){
    for ( auto i : words) {
        if ( changing.find(i) == changing.end()) return false;
        else if (permanent[i] != changing[i] ) return false;
    }
    return true;
}
    vector<int> findSubstring(string toCheck, vector<string>& words) {
        vector <int> answer;
        if (words[0].length()*words.size()> toCheck.length()) return {};
        else if (words.empty() || toCheck.empty()) return {};
    
        unordered_map <string,int> permanent;
        for( int i = 0 ; i < words.size(); i++){
            if ( permanent.find(words[i]) == permanent.end()) permanent.insert({words[i],1});
            else permanent[words[i]]++;
        }
        unordered_map <string, int> changing;
        for ( int i = 0; i < toCheck.length(); i++) {
            changing.clear();
            int l = words[0].length();
            int s = words.size();
            for ( int j = i; j < i + (l*s); j += l ) {
                string temp = toCheck.substr(j,l);
                if ( changing.find(temp) == changing.end()) changing.insert({temp,1});
                else changing[temp]++;
            }
            if (check(permanent,changing,words)) answer.push_back(i);
        }
        return answer;
    }
int main() {
    string toCheck;
    cin>>toCheck;

    int size;
    scanf("%d",&size);

    vector <string> words(size,"");

    for( int i = 0; i < size; i++) {
        cin>>words[i];
    }

    vector <int> ans = findSubstring(toCheck,words);

    for(auto i : ans) cout<<i<<" ";
    getchar();
    return 0;
}