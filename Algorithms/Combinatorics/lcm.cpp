using namespace std;
#include<iostream>
int gcd(int a, int b){
    if(a==0 || b==0)
    return 0;
    else{
        if(a%b==0)
         return b;
        else
         return gcd(b,a%b);
    }
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    int lcm=(n1*n2)/gcd(n1,n2);
    cout<<lcm;
    getchar();
    return 0;
}