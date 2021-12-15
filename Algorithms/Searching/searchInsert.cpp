#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& data,int left,int right,int& element){
   int mid=(left+right)/2;
   if(left>right)
    return -1;
    else{
    if(left==right && data[mid]!=element){
        if(data[mid]<element)
            return mid+1;
        else {
            if(mid==0)
            return 0;
            else
            {
                if(data[mid-1]>element)
                 return mid-1;
                 else
                 return mid;
            }
            
        }
    }
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