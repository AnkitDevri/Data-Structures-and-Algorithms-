using namespace std;
#include <bits/stdc++.h>
void getResults(vector<int>& A, vector<int>& B){
    sort(A.begin(),A.end());
    for(int i = 0; i<B.size(); i++){
        int val = B[i];
        B[i] = upper_bound(A.begin(),A.end(),val) - A.begin();
    }
}
int main(){
    int n,m;
    cin>>n;
    vector<int> A(n,0);
    for(int i = 0; i < n; i++) cin>>A[i];
    cin>>m;
    vector<int>B(m,0);
    for(int i = 0; i<m ; i++) cin>>B[i];
    getResults(A,B);
    for(int i = 0; i<m ; i++){
        cout<<B[i]<<endl;
    }
    return 0;
}