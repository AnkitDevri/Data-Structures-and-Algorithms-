using namespace std;
#include<bits/stdc++.h>
 int SQRT(int start, int end,int& number){
   int mid=(start+end)/2;
   if(mid==0) return 0;

   if(mid<=number/mid && (mid+1)>number/(mid+1)) return mid;

   else if(mid<number/mid) return SQRT(mid,end,number);

   else return SQRT(start,mid,number);
 }
int main(){
    int n;
    cin>>n;
    if(n==1) cout<<1;

    else cout<<SQRT(0,n,n);

    getchar();
    return 0;
}