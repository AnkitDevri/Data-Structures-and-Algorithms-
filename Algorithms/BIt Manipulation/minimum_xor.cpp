using namespace std;
#include<bits/stdc++.h>
int get_min_xor(vector<int>& test_array){
    sort(test_array.begin(),test_array.end());
    int minm = INT_MAX;
    for(auto i : test_array){
        if(minm==0) return 0;
        if(i<test_array.size()-1){
            if(i^(i+1)<minm) minm = i^(i+1);
        }
    }
   return minm;
}
int main(){
    int total_size,element;
    scanf("%d",&total_size);
    vector<int> test_array;
    for(int i=0;i<total_size;i++){
        scanf("%d",element);
        test_array.push_back(element);
    }
    printf("%d",get_min_xor(test_array));
    getchar();
    return 0;
}