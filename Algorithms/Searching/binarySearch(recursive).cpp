using namespace std;
#include<bits/stdc++.h>
 int search(vector<int>& data,int left,int right,int& element){
   int mid=(left+right)/2;
   if(left>right)
    return -1;
    else{
    if(left==right && data[mid]!=element)
     return -1;
    if(data[mid]==element)
    return mid;
    else if(element>data[mid])
    return search(data,mid+1,right,element);
    else
    return search(data,left,mid,element);
    }

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

    int ans= search(data,0,n-1,element); 
       if(ans==-1){
        cout<<"\nNot found";
    }
    else
        cout<<"\n"<<ans;
     
 getchar();
 return 0;
}