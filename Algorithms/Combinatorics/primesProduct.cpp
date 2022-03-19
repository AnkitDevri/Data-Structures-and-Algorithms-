#include <bits/stdc++.h>
using namespace std;
#define M 1000001
#define mod 1000000007
vector<int> primes;
void precompute(){
	bitset<M> bt;
	bt.flip();
	for(int i= 2; i*i<M; i++){
		if(bt[i]){
			for(int j = i*i; j<M; j+=i)
				bt[j]=0;
		}
	}
	for(int i =2; i<M; i++)
		if(bt[i]) primes.push_back(i);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    precompute();
    int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		vector<bool> arr(r-l+1,true);
		int factor;
		for(int i = 0; primes[i]*primes[i]<=r; i++){
			factor=ceil((l*1.0)/primes[i]);
			factor=max(2,factor);
			for(int j = factor*primes[i];  j<=r ; j+=primes[i] ){
				arr[j-l]=false;
			}
		}
		long long ans=1;
		for(int i=0; i<arr.size(); i++){
			if(arr[i]){
				ans =(ans%mod * (l+i)%mod)%mod;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}