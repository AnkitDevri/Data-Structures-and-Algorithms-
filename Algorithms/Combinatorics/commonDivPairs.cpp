using namespace std;
#include<bits/stdc++.h>
vector<int>sieve(1e6+1,2);
void computeSieve(){
    sieve[0]=0,sieve[1]=1;
    for(int i=2;i<=1e6;i++)
     for(int j=i*2;j<=1e6;j+=i)
       sieve[j]++;
}

int main(){
    int pairs,ele;
    scanf("%d",&pairs);
    vector<int> n1(pairs);
    vector<int> n2(pairs);
    for(int i=0;i<pairs;i++){
        scanf("%d",&ele);
        n1[i]=ele;
        scanf("%d",&ele);
        n2[i]=ele;
    }
    computeSieve();
    for(int i=0;i<pairs;i++){
        int gcd=__gcd(n1[i],n2[i]);
        cout<<sieve[gcd]<<"\n";
    }

    getchar();
    return 0;
}