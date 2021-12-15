using namespace std;
#include<bits/stdc++.h>
void towerInstructions(int disks, int from, int to, int by){
    if(disks == 0) return;
    towerInstructions(disks-1,from,by,to);
    cout<<disks<<"["<<from<<" -> "<<to<<"]"<<endl;
    towerInstructions(disks-1,by,to,from);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    int tow1,tow2,tow3;
    cin>>tow1>>tow2>>tow3;
    towerInstructions(size, tow1, tow2, tow3);
    return 0;
}