using namespace std;
#include<bits/stdc++.h>
vector<pair<pair<int,int>,int>> get_frequency(vector<int>& number_array){
    vector<pair<pair<int,int>,int>> final_vector;
    vector<int> frequency(101,0);
    for(int idx=0;idx<number_array.size();idx++){
        frequency[number_array[idx]]++;
        final_vector.push_back(make_pair(make_pair(number_array[idx],idx),0));
    }
    for(int idx=0;idx<number_array.size();idx++){
        final_vector[idx].second=frequency[number_array[idx]];
    }
    return final_vector;
}

bool compare(pair<pair<int,int>,int> item_1,pair<pair<int,int>,int> item_2){
    if(item_1.second==item_2.second){
        if(item_1.first.first==item_2.first.first){
            return item_1.first.second<item_2.first.second;
        }
        else return item_1.first.first<item_2.first.first;
    }
    else return item_1.second<item_2.second;
}

int main(){
    int total_test_case;
    scanf("%d",&total_test_case);
    vector<vector<pair<pair<int,int>,int>>> all_cases;

    for(int idx=0;idx<total_test_case;idx++){
        int total_numbers;
        vector<int> number_array;
         vector<pair<pair<int,int>,int>> data;
        scanf("%d",&total_numbers);
        int item;
        for(int idx=0;idx<total_numbers;idx++){
            scanf("%d",&item);
            number_array.push_back(item);
        }
        data= get_frequency(number_array);
        all_cases.push_back(data);
    }
    for(int idx=0;idx<total_test_case;idx++){
        sort(all_cases[idx].begin(),all_cases[idx].end(),compare);
    }
    for(int i=0;i<total_test_case;i++){
         for(int idx=0;idx<all_cases[i].size();idx++){
             printf("%d ",all_cases[i][idx].first.first);
         }
         printf("\n");
    }
    getchar();
    return 0;
}