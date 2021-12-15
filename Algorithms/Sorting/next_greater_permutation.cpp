using namespace std;
#include<bits/stdc++.h>
void get_greater_permutation(vector<int>& num_array){
    int x,index;
    bool flag=false;
    for(int i=num_array.size()-1;i>0;i--){
        if(num_array[i]<=num_array[i-1]) continue;
        else {
            i--;
            index=i;
            x=num_array[index];
            flag=true;
            break;
        }
    }
    if(!flag){
         sort(num_array.begin(),num_array.end());
         return;
    }
    int to_swap,difference=INT_MAX;
    for(int i=index+1;i<num_array.size();i++){
        if(num_array[i]>x){
        if(difference>num_array[i]-x){
            to_swap=i;
            difference=num_array[i]-x;
        }
        }
    }
    swap(num_array[index],num_array[to_swap]);
    sort(num_array.begin()+index+1,num_array.end());
}
int main(){
    int total_size,element;
    scanf("%d",&total_size);
    vector<int> num_array;
    for(int i=0;i<total_size;i++){
        scanf("%d",&element);
        num_array.push_back(element);
    }
    get_greater_permutation(num_array);
    for(auto i : num_array) printf("%d ",i);
    getchar();
    return 0;
}