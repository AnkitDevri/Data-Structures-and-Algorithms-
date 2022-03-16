#include <bits/stdc++.h>
using namespace std;
#define M 1000001
vector<int> primes(M,0);
void precompute(){
	bitset<M> bt;
	bt.flip();
	for(int i = 2; i*i<=M-1; i++){
		if(bt[i]){
			for(int j = i*i; j<M; j+=i){
				bt[j]=0;
			}
		}
	}
	int count = 0;
	for(int i = 2; i<M; i++){
		if(bt[i]) ++count;
        primes[i] = count;
	}
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
	precompute();
	while(t--){
		int n;
		cin>>n;
		if(n==2) cout<<primes[n]<<endl;
		else{
		cout<<primes[n]-primes[n/2]<<endl;
		}
	}
    return 0;
}