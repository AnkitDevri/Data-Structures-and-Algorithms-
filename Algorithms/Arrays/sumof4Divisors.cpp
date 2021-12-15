#include<bits/stdc++.h>
using namespace std;
  int get4Sum(vector<int> arr){
    int size=arr.size();
        
 int sum=0,ans=0,count=0,i,j;
      for(i=0;i<size;i++){
         for(j=1;j*j<arr[i];j++){
             
              
            if(arr[i]%j==0){
                sum=sum+(arr[i]/j)+j;
                count+=2;
            }
             
         }
          if(j*j==arr[i]){
             sum=sum+j;
             count++;
           }
           if(count==4)
            ans=ans+sum;
            sum=0;count=0;    
           
      }
      return ans; 
  }

int main(){
    int total,element;
    cin>>total;
    vector<int> arr(total);
    for(int i=0;i<total;i++){
    cin>>element;
    arr[i]=element;
    }
    cout<<get4Sum(arr);
    getchar();
   return 0;
}