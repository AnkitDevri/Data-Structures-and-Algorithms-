using namespace std;
#include<bits/stdc++.h>
int get_Single_Number(vector<int>& line){
    int answer=0;
    for(auto i : line) answer^=i;

    return answer;
}
int main(){
    int total_elements,item;
    scanf("%d",&total_elements);
    vector<int> line;
    for(int i=0;i<total_elements;i++){
        scanf("%d",&item);
        line.push_back(item);
    }
    printf("\n%d",get_Single_Number(line));
    getchar();
    return 0;
}