using namespace std;
#include<bits/stdc++.h>
typedef long long in;
 vector<in> sieve(1e6+1,1);
  void computeT(){
      sieve[0]=sieve[1]=0;
      for(in i=2;i*i<=1e6;i++)
         if(sieve[i])
          for(in j=i;i*j<=1e6;j++)
           sieve[i*j]=0;
     
  }
int main(){
    in n,ele;
    cin>>n;
    vector<in> v(n);
    for(in i=0;i<n;i++){
        cin>>ele;
        v[i]=ele;
    }
    computeT();
    for(in i=0;i<n;i++){
       in s=sqrt(v[i]);
         if(s*s==v[i]){
              if(sieve[s]==1)
                cout<<"YES"<<endl;
              else
                cout<<"NO"<<endl;
         }    
        else
         cout<<"NO"<<endl;
    }
   
    getchar();
    return 0;
}