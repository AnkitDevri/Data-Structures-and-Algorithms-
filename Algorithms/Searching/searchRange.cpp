   #include<bits/stdc++.h>
   using namespace std;
    int searchF(vector<int>& data,int left,int right,int& element){
      int mid=(left+right)/2;
   if(left>right)
    return -1;
else{
   if(left==right && data[mid]!=element)
     return -1;
   if(data[mid]==element){
       if(mid==0)
        return 0;
      else if(data[mid-1]==data[mid])
        return searchF(data,left,mid-1,element);
      else 
         return mid;
   }
   
   else if(element>data[mid])
    return searchF(data,mid+1,right,element);
    else
     return searchF(data,left,mid,element);
}
 }
int searchL(vector<int>& data,int left,int right,int& element){
    int mid=(left+right)/2;
   if(left>right)
    return -1;
    else{
      if(left==right && data[mid]!=element)
      return -1;
     if(data[mid]==element){
       if(mid==data.size()-1)
         return mid;
       if(data[mid+1]==element){
           return searchL(data,mid+1,right,element);
       }
        else
        return mid;
   }
   
   else if(element>data[mid])
    return searchL(data,mid+1,right,element);
    else
     return searchL(data,left,mid,element);
    }
    
 }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchF(nums,0,nums.size()-1,target),searchL(nums,0,nums.size()-1,target)};
    }
 
     int main(){
    int n,ele;
    cin>>n;
    vector<int> data(n,0);
    for(int i=0;i<n;i++){
        cin>>ele;
        data[i]=ele;
    }
    int element;
    cin>>element;

    vector<int>ans=searchRange(data,element);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
 getchar();
 return 0;
}
 