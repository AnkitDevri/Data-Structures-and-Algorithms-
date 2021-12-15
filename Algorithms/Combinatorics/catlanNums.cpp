#include <iostream>
using namespace std;
typedef long long in;
int main()

{ 
    in n; cin>>n;

   in c[n+1];

   c[0]=1; c[1]=1;

   for(int i=2;i<=n;i++){
      c[i]=0;
    for(int j=0;j<i;j++)
        c[i]+=c[j]*c[i-1-j];
}

   cout<<c[n]<<" ";
  getchar();
  return 0;

} 