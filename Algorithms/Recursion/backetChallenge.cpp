using namespace std;
#include <bits/stdc++.h>
void formBraces(stack<char>& st, vector<string>& combs, string &str, int& pCount, int& bCount, int pOpen, int bOpen, int pClose, int bClose){
    if(pOpen==pClose && pClose==pCount && bOpen==bClose && bClose==bCount){
        combs.push_back(str);
        return;
    }
    if(pOpen<pCount){
        st.push('(');
        str+='(';
        formBraces(st,combs,str,pCount,bCount,pOpen+1,bOpen,pClose,bClose);
        str.pop_back();
        st.pop();
    }
    if(bOpen<bCount){
        st.push('{');
        str+='{';
        formBraces(st,combs,str,pCount,bCount,pOpen,bOpen+1,pClose,bClose);
        str.pop_back();
        st.pop();
    }
    if(!st.empty()){
        char brace = st.top();
        st.pop();
        if(pClose<pCount && brace=='(') {
            str+=')';
            formBraces(st,combs,str,pCount,bCount,pOpen,bOpen,pClose+1,bClose);
            str.pop_back();
        }
        else if(bClose<bCount && brace=='{'){
            str+='}';
            formBraces(st,combs,str,pCount,bCount,pOpen,bOpen,pClose,bClose+1);
            str.pop_back();
        }
        st.push(brace);
    
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<string> combs;
    string str="";
    stack<char> st;
    formBraces(st,combs,str,n,m,0,0,0,0);
    for(auto i : combs) cout<<i<<endl;
    return 0;
}