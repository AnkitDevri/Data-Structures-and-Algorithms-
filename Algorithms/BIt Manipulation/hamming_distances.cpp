using namespace std;
#include<bits/stdc++.h>
int get_hamming_distance(vector<int>& new_array){
    int answer=0;
  for(int i=31;i>=0;i--){
      int count_of_ones=0;
      long mask =1L<<i;
      for(auto j: new_array){
          if(j & mask) count_of_ones++;
      }
      answer+=count_of_ones*(new_array.size()-count_of_ones);
  }
    return answer;
}
int main(){
    int array_size,array_element;
    scanf("%d",&array_size);

    vector<int> new_array;

    for(int i=0;i<array_size;i++){
        scanf("%d",&array_element);
        new_array.push_back(array_element);
    }

    printf("\n%d",get_hamming_distance(new_array));
    getchar();
    return 0;
}