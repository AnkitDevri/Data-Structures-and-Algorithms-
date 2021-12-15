using namespace std;
#include<bits/stdc++.h>
bool find_pair(vector<int>& test_array,int &input_xor){
 sort(test_array.begin(),test_array.end());
 for(int idx=0;idx<test_array.size();idx++){
    int to_find=test_array[idx]^input_xor;
    if(binary_search(test_array.begin(),test_array.end(),to_find)) return true;
 }
 return false;
}
int main(){
    int total_size,element;
    scanf("%d",&total_size);

    vector<int> test_array;
    for(int idx=0;idx<total_size;idx++){
        scanf("%d",&element);
        test_array.push_back(element);
    }

    int input_xor;
    scanf("%d",&input_xor);
    printf("%d",find_pair(test_array,input_xor));
    getchar();
    return 0;
}