using namespace std;
#include<bits/stdc++.h>
string digiSum(string n,int& k){
    if(k==0){
     return n;
    }
      int num=0;
      for(int i=0;i<n.length();i++)
         num+=int(n[i]-'0');
         k--;
    return digiSum(to_string(num),k);
}

int main(){
    int k;
    string str;
    string g;
    cin>>g>>k;
    str=g;
    for(int i=1;i<k;i++)
       g+=str;
    cout<<digiSum(g,k);
    getchar();
    return 0;
}