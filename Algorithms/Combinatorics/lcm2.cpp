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
int lcm(int n1,int n2,int gcd){
  return (n1*n2)/gcd;
}

int main(){
  int size;
  cin>>size;
  int n1,n2;
  cin>>n1>>n2;
  cout<<(size/n1)+(size/n2)-(size/lcm(n1,n2,gcd(n1,n2)));
  getchar();
  return 0;
}