using namespace std;
#include<iostream>
int gcd(int n1,int n2){
    if(n1==0 || n2==0)
     return 0;
    if(n1%n2==0)
     return n2;
    else
     gcd(n2,n1%n2);
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    cout<<gcd(n1,n2);
    getchar();
    return 0;
}