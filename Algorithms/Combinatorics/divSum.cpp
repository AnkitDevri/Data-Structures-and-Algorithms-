using namespace std;
#include<bits/stdc++.h>
typedef long long in;
 vector<in> sieve(5e5+1,0);
  void getSum(){
      sieve[1]=-1;
      for(in i=2;i*i<=5e5;i++)
          for(in j=i*2;j<=5e5;j+=i)
           sieve[j]+=i;
     
  }
int main(){
    in n,ele;
    cin>>n;
    vector<in> v(n);
    for(in i=0;i<n;i++){
        cin>>ele;
        v[i]=ele;
    }
    getSum();
    for(in i=0;i<n;i++)
    cout<<sieve[v[i]]+1<<endl;
    getchar();
    return 0;
}