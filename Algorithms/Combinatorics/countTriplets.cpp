#include<bits/stdc++.h>
using namespace std;
int countPairs(vector<int>arr,int k){
    int count=0;
    int a,b,c;
    vector<int>counts(k,0);
    for(int i=0;i<arr.size();i++)
        counts[arr[i]%k]++;
    for(int i=0;i<k;i++)
    for(int j=i;j<k;j++){
       a=i,b=j;
       if((a+b)%k==0)
       c=0;
       else
       c=k-((a+b)%k);

       if(a==b && b==c)
       count=count+(counts[a]*(counts[a]-1)*(counts[a]-2))/6;

       else if(a==b)
       count+=((counts[a]*(counts[a]-1))/2)*counts[c];

       else if(a==c)
        count+=((counts[a]*(counts[a]-1))/2)*counts[b];
    
       else if(b==c)
        count+=((counts[b]*(counts[b]-1))/2)*counts[i];

        else
        count+=counts[a]*counts[b]*counts[c];
    }

     return count;
}
int main(){
    int n,k,element;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>element;
        arr[i]=element;
    }
    cout<<countPairs(arr,k);
    getchar();
    return 0;
}