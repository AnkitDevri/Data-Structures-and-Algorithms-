using namespace std;
#include<bits/stdc++.h>
vector<int> compute_answer(vector<vector<int>>& all_cases,vector<int>& item_list){
    for(int i=0;i<all_cases.size();i++){
        sort(all_cases[i].begin(),all_cases[i].end());
        for(int j=1;j<all_cases[i].size();j++){
            all_cases[i][j]=all_cases[i][j]+all_cases[i][j-1];
        }
    }
    vector<int> answer;
    for(int i=0;i<item_list.size();i++){
        answer.push_back(all_cases[i][all_cases[i].size()-1]-(2*all_cases[i][item_list[i]-1]));
    }
    return answer;
}
int main(){
    int total_cases;
    scanf("%d",&total_cases);

    int size;
    int items,weights;
    vector<vector<int>> all_cases;
    vector<int> item_list;
    for(int i=0;i<total_cases;i++){
        scanf("%d",&size);
        scanf("%d",&items);
        item_list.push_back(items);
        vector<int> sample;
        for(int j=0;j<size;j++){
            scanf("%d",&weights);
            sample.push_back(weights);
        }
        all_cases.push_back(sample);
    }

    vector<int> output=compute_answer(all_cases,item_list);
    for(int i=0;i<output.size();i++){
      cout<<output[i]<<endl;
    }
    getchar();
    return 0;
}