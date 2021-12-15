using namespace std;
#include<bits/stdc++.h>
int compute_query(vector<int>& test_array,int start,int end){
    if(start==0) return test_array[end];
    return test_array[start-1]^test_array[end];
}
int main(){
    int total_size,element;
    scanf("%d",&total_size);

    vector<int> test_array;
    for(int idx=0;idx<total_size;idx++){
        scanf("%d",&element);
        test_array.push_back(element);
    }

    int total_queries;
    scanf("%d",&total_queries);
    
    vector<vector<int>> query_array(total_queries,vector<int>(2,0));

    for(int idx1=0;idx1<total_queries;idx1++){
        for(int idx2=0;idx2<2;idx2++){
            scanf("%d",query_array[idx1][idx2]);
        }
    }
    
    vector<int> test_array_precomputed(total_size,0);
    test_array_precomputed[0]=test_array[0];
    for(int idx=1;idx<total_size;idx++){
        test_array_precomputed[idx]=test_array[idx]^test_array_precomputed[idx-1];

    }
   
    for(int idx=0;idx<total_queries;idx++){
             printf("\n%d",compute_query(test_array_precomputed,query_array[idx][0],query_array[idx][1])); 
    }
    getchar();
    return 0;
}