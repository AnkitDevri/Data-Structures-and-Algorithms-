#include <bits/stdc++.h>
using namespace std;
#define M 1000001
vector<int> spf(M,0);
void precompute(){
	bitset<M> bt;
	bt.flip();
	for(int i = 2; i*i<= 1000000; i++){
		if(bt[i]){
			for(int j = i*i; j<=1000000; j+=i){
				bt[j]=0;
				spf[j]=i;
			}
		}
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
		map <int,int> mp;
			while(n>1){
					int num = spf[n];
					int count = 0;
					if(num==0){
						mp[n]=1;
						break;
					}
					while(n%num==0){
						n/=num;
						count++;
					}
			   mp[num]=count;
			}
		for(auto i : mp){
			cout<<i.first<<" "<<i.second<<endl;
		}
	}
    return 0;
}