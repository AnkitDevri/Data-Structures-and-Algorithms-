#include<bits/stdc++.h>
using namespace std;
long get_single_element(vector<int>& line){
    long answer=0;
    
    for(int i=31;i>=0;i--){
        int count=0;
        long mask = 1L<<i;
        for(auto j : line){
            if((j & mask)!=0) count++;
        }
        if(count%3!=0) answer|=mask;
        
    }
    return answer;
}
int main(){
    int total_elements,element;
    scanf("%d",&total_elements);
    vector<int> line;
    for(int i=0;i<total_elements;i++){
        scanf("%d",&element);
        line.push_back(element);
    }
    printf("%ld",get_single_element(line));
    getchar();
    return 0;
}