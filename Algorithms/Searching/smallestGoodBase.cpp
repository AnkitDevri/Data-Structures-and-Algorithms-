using namespace std;
#include<bits/stdc++.h>
int smallestGbase(long long int& n){
    for(int i=63;i>=1;i--){
       long long int left=2;
       long long int right=n-1;

        while(left<=right){

            int breaker=0;
            long long int mid=(left+right)/2;
            long long int sum=1;
            long long int x=1;

            for(int j=1;j<i;j++){
                 if((n-sum)/mid<x){
                     breaker=1;
                     break;
                    }
                  x*=mid;
                  sum+=x;
            }
            
            if(sum>n || breaker==1) right=mid-1;
             else if(sum<n)  left=mid+1;
             else return mid;


        }
    }
}
int main(){
    long long int n;
    cin>>n;
    cout<<smallestGbase(n);
    getchar();
    return 0;
}