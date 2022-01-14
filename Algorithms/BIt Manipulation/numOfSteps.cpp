using namespace std;
#include<bits/stdc++.h>
int numSteps(string s){
  int ans=0;
       while(s.size()!=1)
       {
           if(s.back()=='0')
           {
                s.pop_back();
                ans++;
               continue;
           }
           bool flag=false;
           for(int i=s.size()-1;i>=0;i--)
           {
               if(s[i]=='0')
               {
                   s[i]='1';
                   flag=true;
                   break;
               }
               s[i]='0';
           }
           if(!flag)
              s="1"+s;
           ans++;
       }
        return ans;
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