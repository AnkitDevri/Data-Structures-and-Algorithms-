using namespace std;
#include<bits/stdc++.h>
int getMinSwaps(vector<int>sample,int k){
    int count=0;
    int legalCount=0;
    int toswap;
    for(int i=0;i<sample.size();i++)
     if(sample[i]<=k)
      count++;
    for(int i=0;i<count;i++)
      if(sample[i]<=k)
       legalCount++;
   
    int legal=legalCount;

    for(int i=count;i<sample.size();i++){
     if(sample[i]<=k)
       ++legalCount;
     if(sample[i-count]<=k)
       --legalCount;
    
      legal=max(legal,legalCount);
     
    }
    return count-legal;
     
}
int main(){
    vector<int> sample(7);
    int k,element;
    cin>>k;
    for(int i=0;i<sample.size();i++){
     cin>>element;
     sample[i]=element;
    }
    cout<<getMinSwaps(sample,k);
    getchar();
    return 0;
}