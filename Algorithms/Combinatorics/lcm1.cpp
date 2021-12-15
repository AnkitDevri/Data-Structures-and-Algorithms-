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
    int size,LCM;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    
    LCM= lcm(arr[0],arr[1],gcd(arr[0],arr[1]));

    for(int i=2;i<size;i++){
      LCM=lcm(LCM,arr[i],gcd(LCM,arr[i]));
    }
   
    cout<<LCM;
    getchar();
    return 0;
}