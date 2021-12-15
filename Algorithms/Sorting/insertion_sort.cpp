using namespace std;
#include<bits/stdc++.h>
void insertion_sort(vector<int>& num_array){
    for(int i=0;i<num_array.size()-1;i++){
        for(int idx=i+1;idx>=0;idx--){
            if(idx){
                if(num_array[idx]<num_array[idx-1]) swap(num_array[idx],num_array[idx-1]);
                else break;
            }
        }
    }
}
int main(){
    int total_elements,element;
    scanf("%d",&total_elements);

    vector<int> num_array;
    for(int idx=0;idx<total_elements;idx++){
        scanf("%d",&element);
        num_array.push_back(element);
    }
    insertion_sort(num_array);
    
    for(auto i: num_array) printf("%d ",i);
    getchar();
    return 0;
}