using namespace std;
#include<bits/stdc++.h>
double myPow(double& x, int n) {
       double ans;
        if(n==0)
            return 1;
        ans=myPow(x,n/2);
        if(n%2==0)
            return ans*ans;
        else{
            if(n>0)
                return x*ans*ans;
            else
                return ans*ans/x;
        }
    }
int main(){
    double n;
    int k;
    cin>>n>>k;

    cout<<myPow(n,k);
   
    getchar();
    return 0;
}