using namespace std;
#include<bits/stdc++.h>
int count1bits(long num){
    int count=0;
    long mask = 1L<<31;
    for(int i=0;i<32;i++,mask>>=1){
        if(num & mask ) count++;
        else continue;
    }
    return count;
}

int fastCount(long num){
    int count=0;
    while(num){
        count++;
        num = num & (num-1);
    }
    return count;
}
int main(){
    long num;
    cin>>num;
    cout<<count1bits(num)<<endl;
    cout<<fastCount(num);
    getchar();
    return 0;
}