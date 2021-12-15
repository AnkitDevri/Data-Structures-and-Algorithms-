using namespace std;
#include<bits/stdc++.h>
 void permutations(vector<int>& arr,int index,int& count){
     if(index==arr.size()){
        bool decide=0;
       for(int i=1;i<=arr.size();i++){
        if(arr[i-1]%i==0 || i%arr[i-1]==0)
            decide=1;
        else{
         decide=0;
         break;
        }
       }
        if(decide)
        count++;
         return;
     }
      
     for(int i=index;i<=arr.size();i++){
         swap(arr[index-1],arr[i-1]);
         permutations(arr,index+1,count);
         swap(arr[index-1],arr[i-1]);
     }
 }
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=1;i<=n;i++)
     arr.push_back(i);
     int count=0;
     permutations(arr,1,count);
     cout<<count;
    getchar();
    return 0;
}