using namespace std;
#include <bits/stdc++.h>
    bool isPowerOfTwo(int n) {
        int num = 1;
        for(int i = 1; i <=31 ; i++){
            if(num == n) return true;
            num = num<<1;
        }
        return false;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int num;
    cin>>num;
    cout<<isPowerOfTwo(num);
    return 0;
}