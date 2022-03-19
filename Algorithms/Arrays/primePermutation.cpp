#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
vector<long long> fact(101,0);
vector<int> pCount(101,0);
void precompute(){
    bitset<101> bt;
    bt.flip();
    for(int i = 2; i*i<=100; i++){
	if(bt[i]){
	    for(int j = i*i; j<=100; j+=i){
		bt[j]=0;
	    }
	}
    }
    int count = 0;
    for(int i = 2; i<pCount.size(); i++){
	if(bt[i]) count++;
	pCount[i] = count;
    }
    
    fact[0]=1;
    fact[1]=1;
    for(int i = 2; i<=100; i++){
           long long val = 0;
           val=((fact[i-1] % mod )* i )%mod;
            fact[i] = val % mod;
    }
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
	int n;
	cin>>n;
	cout<<((fact[pCount[n]] % mod)*(fact[n-pCount[n]] % mod)) % mod;
    }
    return 0;
}