using namespace std;
#include <bits/stdc++.h>
int child1(int i) {return 2*i;}
int child2(int i) {return 2*i + 1;}

void heapify (vector<int>& heapArray, int idx){
    if(child1(idx) > heapArray.size()-1 || child2(idx) > heapArray.size()-1 ) return;

    heapify(heapArray,child1(idx));

    if(child1(idx) < heapArray.size()-1){
        if( heapArray[idx] < heapArray[child1(idx)])
            swap(heapArray[idx],heapArray[child1(idx)]);
    }

    heapify(heapArray,child2(idx));

     if(child2(idx) < heapArray.size()-1){
        if( heapArray[idx] < heapArray[child2(idx)])
            swap(heapArray[idx],heapArray[child2(idx)]);
    }
    

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> heapArray(size+1,0);
    for( int i = 1; i < heapArray.size(); i++) cin>>heapArray[i];
    heapify(heapArray,1);
    for( int i = 1 ; i < heapArray.size(); i++) cout<<heapArray[i]<<" ";
    return 0;
}