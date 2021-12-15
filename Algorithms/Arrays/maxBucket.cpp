using namespace std;
#include<bits/stdc++.h>
int getMaxConGap(vector<int>arr){
    if(arr.size()==2)
     return *max_element(arr.begin(),arr.end())-*min_element(arr.begin(),arr.end());                                         // the case where there are only two elements then it fails to compute anything
    
    int answer=INT_MIN;
    int Max=*max_element(arr.begin(),arr.end());
    int Min=*min_element(arr.begin(),arr.end());

    if(Max==Min)
     return 0; 
                                             //when all values are equal
    int gaps=arr.size()-1;
    int gapSize=(Max-Min)/gaps;
    if((Max-Min)%gaps!=0)                             //when the gaps do not divide the difference completely
     gapSize++;

    vector<int> bucketMin(gaps+1,INT_MAX);                //extra bucket for the last element
    vector<int> bucketMax(gaps+1,INT_MIN);                //extra bucket for the last element
    //filter
    for(int i=0;i<arr.size();i++){
     int j=(arr[i]-Min)/gapSize;
        bucketMin[j]=min(bucketMin[j],arr[i]);
        bucketMax[j]=max(bucketMax[j],arr[i]);
             
    }
    int temp=0;
    for(int i=0;i<gaps;i++){
        if(bucketMin[i+1]==INT_MAX){
            if(!temp)                                              // for handling the case when the buckets remain empty
             temp=bucketMax[i];                                    // to get the correct answer we take the max of last bucket
             continue;                                             // till we reach a proper bucket 
        }
         if(temp){
             answer=max(answer,bucketMin[i+1]-temp);
             temp=0;
         }
         
        answer=max(answer,bucketMin[i+1]-bucketMax[i]);
    }
      
  return answer;
}
int main(){
    int size,element;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>element;
        arr[i]=element;
    }
    cout<<getMaxConGap(arr);
    getchar();
    return 0;
}