using namespace std;
#include <bits/stdc++.h>

string removeDuplicates ( string& s) {

    string answer ="";
    stack <char> st;
    vector <int> freq(26,0);
    vector <bool> present(26,false);

    for ( int i = 0; i < s.length(); i++) freq[s[i]-'a']++;

    st.push(s[0]);
    freq[s[0]-'a']--;
    present[s[0]-'a'] = true;

    for ( int i = 1; i < s.length(); i++) {
        freq[s[i]-'a']--;
        if(present[s[i]-'a']) continue;
        else {
            if(st.top() < s[i]) {
                st.push(s[i]);
                present[s[i]-'a'] = true;
            }
            else {
                while (!st.empty() && st.top() > s[i] && freq[st.top()-'a'] > 0){
                        present[st.top()-'a'] = false;
                        st.pop();    
                }
                st.push(s[i]);
                present[s[i]-'a'] = true;
            }
        }
    }
    while (!st.empty()){
        answer = answer + st.top();
        st.pop();
    }

    reverse(answer.begin(),answer.end());
    return answer;

}
int main() {
    string s;
    cin>>s;
    cout<<removeDuplicates(s);
    getchar();
    return 0;
}