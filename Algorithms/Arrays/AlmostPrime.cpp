#include <bits/stdc++.h>
using namespace std;
#define M 3001
vector<int> ans(M,0);
vector<int> spf(M,0);

void precompute(){
	bitset<M> bt;
	bt.flip();
	for(int i = 2; i*i<M; i++){
		if(bt[i]){
			for(int j = i*i; j<M;j+=i){
				bt[j]=0;
				spf[j]=i;
			}
		}
	}
	
	for(auto i = 2; i<M; i++){
		unordered_set <int> s;
		int num = spf[i];
        int idx = i;
        while(num!=0 && idx%num==0){
            s.insert(num);
            idx/=num;
            num=spf[idx];
        }

        if(num==0) s.insert(idx);
        if(s.size()==2) ans[i]=1;
    }
    for(int i = 1; i <M; i++){
        ans[i]+=ans[i-1];
    }
	
}
int main() {
    /*#ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    */
	precompute();
		int n;
		cin>>n;
		cout<<ans[n]<<endl;
    return 0;
}