using namespace std;
#include<bits/stdc++.h>
 vector<vector<int>> getQuadruplets(vector<int>& arr){
     vector<vector<int>> answer;
     if(arr[0]>0) return answer;

     for(int i=0;i<arr.size()-4;i++){
         int idx=i+1;
         int count=0;
        /* while(arr[i+1]==arr[i]){
             count++;
            if(count) i++;
         }*/
         

         for(int j=idx;j<arr.size()-3;j++){
             int idx1=j+1;
             int count=0;
          /*   while(arr[j+1]==arr[j]){
                 count++;
                 if(count) j++;
             } */
             

             int start=idx1;
             int end=arr.size()-1;

             while(start<end){
                if(arr[idx]+arr[idx1]+arr[start]+arr[end]==0){
                    int e1=arr[start];
                    int e2=arr[end];

                    while(arr[start+1]==e1) start++;
                    while(arr[end-1]==e2) end--;

                    answer.push_back({arr[idx],arr[idx1],arr[start],arr[end]});
                    end--;
                }
                else if(arr[idx]+arr[idx1]+arr[start]+arr[end]<0) start++;
                else end--;
            }
         }
     }
     return answer;
 }
int main(){
    int total_elements,element;
    cin>>total_elements;
    vector<int> arr(total_elements);
    
    for(int i=0;i<total_elements;i++){
        cin>>element;
        arr[i]=element;
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>> Solution=getQuadruplets(arr);

    for(int i=0;i<Solution.size();i++){
        for(int j=0;j<Solution[i].size();j++){
            cout<<Solution[i][j]<<" ";
        }
        cout<<endl;
    }
    getchar();
    return 0;
}