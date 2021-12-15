using namespace std;
#include<bits/stdc++.h>
pair<int,int> get_non_repeating(vector<int>& test_array){
    int total_xor=0;
    for(int idx=0;idx<test_array.size();idx++){
        total_xor^=test_array[idx];
    }
    int check_idx;
    for(int idx=31;idx>=0;idx--){
        long mask =1L<<idx;
        if(mask & total_xor ){
            check_idx=idx;
            break;
        }
    }
    long mask =1L<<check_idx;
    int first_number=0;
    int second_number=0;
    for(int idx=0;idx<test_array.size();idx++){
        if(mask & test_array[idx]) first_number^=test_array[idx];
        else second_number^=test_array[idx];
    }
    return make_pair(first_number,second_number);
}

int main(){
    int total_size,element;
    scanf("%d",&total_size);

    vector<int> test_array(total_size,0);
    
    for(int idx=0;idx<total_size;idx++){
        scanf("%d",&element);
        test_array[idx]=element;
    }

    pair<int,int> answer = get_non_repeating(test_array);
    printf("%d , %d",answer.first,answer.second);
    getchar();
    return 0;
}