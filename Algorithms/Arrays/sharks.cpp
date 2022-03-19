#include <bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    unordered_map<int,int> msum;
    unordered_map<int,int> mdiff;
    int k = 1;
    while(n--){
	int i, j;
	cin>>i>>j;
	int sum = i+j;
	int adiff = i-j;
	if(adiff<0) adiff=k-adiff;
	    msum[sum]++;
	    mdiff[adiff]++;
    }
    long long clashes = 0;
    for( auto i = msum.begin(); i!=msum.end();i++){
	    int num = i->second;
        cout<<num<<" ";
	    clashes+= (num*(num-1))/2;
    }
    cout<<endl;
    for( auto j = mdiff.begin(); j!=mdiff.end(); j++){
	    int num = j->second;
        cout<<num<<" ";
	    clashes+=(num*(num-1))/2;
    }
    cout<<endl;
    cout<<clashes<<endl;
    return 0;
}