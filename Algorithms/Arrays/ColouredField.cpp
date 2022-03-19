#include <bits/stdc++.h>
using namespace std;
void precompute(vector<vector<int>>& mat,int k){
    while(k--){
	int i,j;
	cin>>i>>j;
	mat[i-1][j-1]=-1;
    }
    int count = 1;
    for(int i = 0; i< mat.size(); i++){
	for(int j = 0; j<mat[i].size(); j++){
	    if(mat[i][j]==-1) continue;
	    else {
		if(count>3) count = 1;
		mat[i][j]=count;
		count++;
	    }
	}
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    vector<vector<int> > mat(n,vector<int>(m,0));
    precompute(mat,k);
    while(t--){
	int i, j;
	cin>>i>>j;
	if(mat[i-1][j-1]==-1) cout<<"Waste"<<endl;
	else if(mat[i-1][j-1]==1) cout<<"Carrots"<<endl;
	else if(mat[i-1][j-1]==2) cout<<"Kiwis"<<endl;
	else cout<<"Grapes"<<endl;
    }
    return 0;
}