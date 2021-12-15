#include<bits/stdc++.h>
using namespace std;

int main()
{ 
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    char b[25];
    for(int i = 0 ; i < 25; i++) cin>>b[i];
    string newstr = string(b);
    newstr.erase(newstr.size()-1);
 
    for(auto i : newstr) cout<<i;
    cout<<endl;
    string nw = newstr.substr(0,10);
    
    string a;
    cin>>a;
    char arr[a.length()];
    strcpy(arr,a.c_str());
    for( auto i : arr) cout<<i;
    cout<<endl;
    string joint;
    joint = a;
    joint.insert(4,newstr.substr(0,5));
    cout<<joint;
   cout<<endl<<newstr<<endl;
   cout<<nw;
    return 0;
}