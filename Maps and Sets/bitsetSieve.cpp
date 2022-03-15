#include<bits/stdc++.h>
using namespace std;
#define M 1000001
bitset<M> bt;
vector<int> counts(M,0);
void preCompute(){
    bt.flip();
	for(int i = 2; i*i<= 1000000; i++){
		if(bt[i]){
		for(int j = i*i; j<=1000000; j+=i)
			bt[j]=0;
		}
	}
	for(int i = 2; i <counts.size(); i++){
		if(bt[i]){
			counts[i]=counts[i-1]+1;
            continue;
		}
		counts[i]=counts[i-1];
	}
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int t;
	cin>>t;
	preCompute();
	while(t--){
		int n;
		cin>>n;
		cout<<counts[n];
	}
    return 0;
}