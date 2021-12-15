using namespace std;
#include<bits/stdc++.h>
vector<int> sPrime(999999,-1);

void preCompute(vector<int>& sPrime){
    vector<bool> q(999999,true);
    q[0]=q[1]=false;
    for(int i=2;i*i<=999999;i++)                      
       if(q[i])
         for(int j=i*i;j<=999999;j+=i){
             q[j]=false;
             sPrime[j]=i;
         }

              
}

 void getFactors(int n){
         while(n%sPrime[n]==0){
           if(sPrime[n]==-1){
               cout<<n<<" ";
               break;
           }  
             cout<<sPrime[n]<<" ";
             n=n/sPrime[n];
         }
      
 }
int main(){
    int n,element;
    cin>>n;
    vector<int> query(n);
    for(int i=0;i<n;i++){
        cin>>element;
        query[i]=element;
    }
    preCompute(sPrime);
    for(int i=0;i<n;i++){
          getFactors(query[i]);
          cout<<endl;
    }
    
    getchar();
    return 0;
}