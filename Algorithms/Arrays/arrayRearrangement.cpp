#include<bits/stdc++.h>
using namespace std;
 void rearrange(vector<int>& arr){
     for(int i=0;i<arr.size();i++){
         if(arr[i]>=0){                        // for checking whether the element has been changed before
             int idx=arr[i],val=i;             // storing the index values
             while(idx!=i){                    // before the cylce reaches its starting point again it needs to change the remaining elements 
                 int temp=arr[idx];            // storing the remaining element index values
                 arr[idx]=-(val+1);            // altering the values as negative to diffrentiate the changes and adding 1 for the case of 0
                 val=idx;
                 idx=temp;
             }
             arr[idx]=-(val+1);                //changing the value of the starting point of the cycle at the end to stop the cycle.
         }
     }

  for(int i=0;i<arr.size();i++)
    arr[i]=arr[i]*(-1)-1;                    //reverting the original values 
 }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int n,element;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
         cin>>element;
         arr[i]=element;
    }
    rearrange(arr);
     for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
    getchar();
    return 0;
}