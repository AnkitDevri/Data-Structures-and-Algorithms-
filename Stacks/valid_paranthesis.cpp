using namespace std;
#include <bits/stdc++.h>
bool isValid( string s) {
    stack <char> st;
    for ( int i = 0; i < s.size(); i++) {
        if ( s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
            continue;
        }

        else if (st.empty()) return false;

        else if ( st.top() != '(' && s[i] == ')') return false;

        else if ( st.top() != '{' && s[i] == '}') return false;

        else if ( st.top() != '[' && s[i] == ']') return false;

        st.pop();
    }
    return st.empty();
}
int main() {
    string s;
    cin>>s;
    cout<<isValid(s);
    getchar();
    return 0;
}