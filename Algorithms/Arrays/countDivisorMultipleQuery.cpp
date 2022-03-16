#include <bits/stdc++.h>
using namespace std;
#define M 1000001
vector<int> spf(M,0);
void precompute(){
	bitset<M> bt;
	bt.flip();
	for( int i = 2; i*i<=1000000; i++){
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
		vector<int> arr(n,0);
		for(auto i = 0; i<n; i++) 
			cin>>arr.at(i);
		for(auto i = 0; i<arr.size(); i++){
			unordered_set <int> s;
			int num = spf[arr[i]];
			while(num!=0 && arr[i]%num==0){
				s.insert(num);
				arr[i]/=num;
				num=spf[arr[i]];
			}
			if(num==0) 
				s.insert(arr.at(i));
			cout<<s.size()<<" ";
		}
        cout<<endl;
	}
    return 0;
}