using namespace std;
#include<bits/stdc++.h>
int numSteps(string s){
    int count = 0;
    auto g = s.find('1');
    while(g!=string::npos){
    if((s[s.size()-1]-'0')%2 ==0){
        s=s+"1";
    }
    else{
        s.replace(s.size()-1,1,"0");
        int i = 2;
        while(s[s.size()-i]=='1'){
            s.replace(s.size()-i,1,"0");
        }
        s.replace(s.size()-i,1,"1");
    }
    count++;
    }
    return count;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    cout<<numSteps(s);
    return 0;
}