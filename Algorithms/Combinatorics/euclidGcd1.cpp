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
int main()
{
    int total,temp;
    cin>>total;
    int arr[total];
    for(int i=0;i<total;i++)
    cin>>arr[i];
    temp=gcd(arr[0],arr[1]);
    cout<<endl<<"GCD : ";
    for(int i=1;i<total-1;i++){
     if(temp==1)
      break;
     temp=gcd(temp,arr[i+1]);
    }
      
    cout<<temp;
    
    getchar();
    return 0;
}