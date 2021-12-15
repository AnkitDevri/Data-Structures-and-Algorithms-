using namespace std;
#include<bits/stdc++.h>
 int maxVal(vector<int>& arr,int left,int right){
    if(left==right)
     return arr[left];
    return max(maxVal(arr,left,((left+right)/2)),maxVal(arr,((left+right)/2)+1,right));
 }
int main(){
    int n,ele;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>ele;
        arr[i]=ele;
    }
    cout<<maxVal(arr,0,n-1);
    getchar();
    return 0;
}