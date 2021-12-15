using namespace std;
#include<bits/stdc++.h>
bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first < b.first)return true;
    return false;
}
int get_max_index_diff(vector<int>& num_array){
    vector<int> suffixMax(num_array.size(),0);
    vector<pair<int,int>> sorted;
    
    
    for(int i=0;i<num_array.size();i++){
        sorted.push_back(make_pair(num_array[i],i));
    }
    sort(sorted.begin(),sorted.end(),compare);

    suffixMax[num_array.size()-1]=sorted[num_array.size()-1].second;

    for(int i=num_array.size()-2;i>=0;i--){
       suffixMax[i]=max(suffixMax[i+1],sorted[i].second);
    }
    int answer=INT_MIN;
    for(int i=0;i<num_array.size();i++){
        answer=max(answer,suffixMax[i]-sorted[i].second);
    }
    return answer;
}
int main(){
    int size,element;
    scanf("%d",&size);
    vector<int> num_array;
    for(int i=0;i<size;i++){
        scanf("%d",&element);
        num_array.push_back(element);
    }
    printf("%d",get_max_index_diff(num_array));
    getchar();
    return 0;
}