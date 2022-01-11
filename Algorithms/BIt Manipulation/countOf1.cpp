using namespace std;
#include<bits/stdc++.h>
int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
            if(n%2!=0) count++;
            n=n>>1;
        }
        return count;
    }
int main(){
    uint32_t n;
    cin>>n;
    cout<<hammingWeight(n);
    return 0;
}