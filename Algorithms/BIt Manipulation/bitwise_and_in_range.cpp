using namespace std;
#include<bits/stdc++.h>
long calcBitAnd(long left,long right){
    if(left==right) return left;
    long mask= 1L<<31;
    long answer=0;
    while((mask & left) == (mask & right)){
        if(mask & left) answer+=mask;
        mask>>=1;
    }
    return answer;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    long left,right;
    cin>>left>>right;
    cout<<calcBitAnd(left,right);
    getchar();
    return 0;
} 
 
 