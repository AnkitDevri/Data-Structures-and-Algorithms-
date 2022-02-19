using namespace std;
#include<bits/stdc++.h>
void initFreq(vector<int>& nums,int arr[],int pos){
    for(int i = 0; i<10; i++) arr[i]=0;
    for(int i = 0; i < nums.size(); i++){
        arr[((nums[i]/pos)%10)]++;
    }
    for(int i = 1; i < 10; i++ ){
        arr[i]=arr[i]+arr[i-1];
    }
}
void radixSort(vector<int>& nums){
    int freq[10]={};
    vector<int> temp(nums.size(),0);
    int MAX = *max_element(nums.begin(),nums.end());
    

    for(int i = 1; MAX/i>0; i*=10){
        initFreq(nums,freq,i);
        for(int j = nums.size()-1; j>=0; j--){
            int idx= ((nums[j]/i)%10);
            temp[freq[idx]-1] = nums[j];
            freq[idx]--;
        }
        nums=temp;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> arr(size,0);
    for( int i = 0 ; i < arr.size() ; i++ ) cin>> arr[i];
    radixSort(arr);
    for( int i = 0; i < arr.size(); i++) cout<<arr[i]<<endl;
    return 0;
}