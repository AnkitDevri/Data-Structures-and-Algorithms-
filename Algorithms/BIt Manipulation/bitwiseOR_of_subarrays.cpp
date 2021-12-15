using namespace std;
#include<bits/stdc++.h>
long get_bitwiseOR_subarrays(vector<int>& test_array){
    long answer = 0;
    for(int i=31;i>=0;i--){
        long mask = 1L<<i;
        long next = test_array.size();
        for(int j=test_array.size()-1;j>=0;j--){
            if(test_array[j] & mask) next=j;
            answer+=((test_array.size()-next)*mask);
        }
    }
    return answer;
}
int main(){
    int total_size,element;
    scanf("%d",&total_size);
    vector<int> test_array;
    for(int i=0;i<total_size;i++){
        scanf("%d",&element);
        test_array.push_back(element);
    }
    printf("\n%ld",get_bitwiseOR_subarrays(test_array));
    getchar();
    return 0;
}