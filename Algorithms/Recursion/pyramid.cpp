using namespace std;
#include <bits/stdc++.h>
void getGlasses(vector<vector<float>>& pyramid,int i,int j){
    if(j>=pyramid.size() || i>=pyramid.size())
        return;
    if(pyramid[i][j]<1) 
        return;
    float wine = pyramid[i][j]-1;

    if(i+1<pyramid.size() && j+1<pyramid.size()){
        pyramid[i+1][j]+=wine/2;
        pyramid[i+1][j+1]+=wine/2;
    } 
    pyramid[i][j]=1;
    getGlasses(pyramid,i+1,j);
    getGlasses(pyramid,i+1,j+1);

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,t;
    cin>>n;
    cin>>t;
    vector<vector<float>> pyramid(n,vector<float>(n,0));
    pyramid[0][0]=t;
    getGlasses(pyramid,0,0);
    int count = 0;
    for(int i = 0; i<pyramid.size(); i++){
        for(int j = 0; j<=i; j++){
            if(pyramid[i][j]==1) count++;
        }
    }
    cout<<count<<endl;
    return 0;
}