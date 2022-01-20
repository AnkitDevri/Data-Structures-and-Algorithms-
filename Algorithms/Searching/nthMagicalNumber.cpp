using namespace std;
#include<bits/stdc++.h>
long long divisor = 1e9+7;
int nthMagicalNumber(int n, int a, int b) {
        int answer = 0;
        long long lcm =(a*b)/__gcd(a,b);
        long long l = min(a,b),r = n*min(a,b);
        while(l<=r){
            long long m = l+ (r-l)/2;
            long long  num = (m/a)+(m/b)-(m/lcm);
            if(num==n) {answer = m%divisor; break; }
            else if ( num < n) l = m + 1;
            else r = m - 1;
        }
        return answer;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,a,b;
    cin>>n>>a>>b;
    cout<<nthMagicalNumber(n,a,b);
    return 0;
}