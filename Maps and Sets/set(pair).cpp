using namespace std;
#include<iostream>
#include<set>
#include<conio.h>
int main(){
    set<pair<int,int>> bpair;
    pair<int,int> x;
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    for(int i=1;i<size;i+=2){
    x = make_pair(arr[i-1],arr[i]);
    bpair.insert(x);
    }
    
    for(auto x:bpair)
    cout<<"("<<x.first<<","<<x.second<<")"<<endl;
    getch();
    return 0;
}