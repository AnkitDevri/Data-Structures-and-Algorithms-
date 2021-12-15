using namespace std;
#include<bits/stdc++.h>
 void fastFactorization(vector<int> query){
  int n=query.size();
  int max=*max_element(query.begin(),query.end());
  vector<int>seive;
  vector<int>count(max);
  vector<bool>q(max,true);
  q[0]=q[1]=false;
  int i,j,answer=1;
//Pre Processing for seive starts
  for(int i=2;i*i<=max;i++)
     if(q[i]){
     for(int j=i*i;j<=max;j+=i)
        q[j]=false;
    }
 // creating the seive full of prime numbers below
     for(int i=2;i<=max;i++)
        if(q[i])
         seive.push_back(i);
   

//Pre Processing ends
    for(int i=0;i<n;i++){
      int temp=query[i];
      for(int j=0;seive[j]<=sqrt(query[i]);j++){
         count[j]=0;
         while(temp%seive[j]==0){
             temp=temp/seive[j];
             cout<<seive[j]<<" ";
             count[j]++;
         }
    }
        if(temp!=1){
          cout<<temp;
          answer=2;
        }
        cout<<endl;
    }  
     for(int i=0;i<count.size();i++)
      if(count[i]!=0)
      answer=answer*(count[i]+1);
   
   cout<<answer;
 }
int main(){
    int size,element;
    cin>>size;
    vector<int> query(size);
    for(int i=0;i<size;i++){
        cin>>element;
        query[i]=element;
    }
    fastFactorization(query);
    getchar();
    return 0;
}