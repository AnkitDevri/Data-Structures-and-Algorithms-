using namespace std;
#include<iostream>
void print(int x,int origin){
  if(x==0)
   return;
  else{
    cout<<origin-x+1<<" ";
    x--;
    print(x,origin);
    
  }
}
void printx(int x){
    if(x==0)
    return;
    cout<<x<<" ";
    --x;
    printx(x);
}
void printImproved(int x){
    if(x<=0)
    return;
    printImproved(x-1);
    cout<<x<<" ";
}
int main(){
    int x;
    cin>>x;
    int origin=x;
    print(x,origin);
    cout<<endl;
    printx(x);
     cout<<endl;
    printImproved(x);
    getchar();
    return 0;
}