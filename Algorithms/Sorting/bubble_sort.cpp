using namespace std;
#include<bits/stdc++.h>
void bubble_sort(vector<int>& num_array){
    bool sorted=false;
    for(int i=0;i<num_array.size();i++){
        if(sorted) break;
        else sorted=true;
        
        for(int j=1;j<num_array.size()-i;j++){
            if(num_array[j]<num_array[j-1]) {
                swap(num_array[j],num_array[j-1]);
                sorted=false;
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

    bubble_sort(num_array);
    for(auto i: num_array) printf("%d ",i);
    getchar();
    return 0;
}