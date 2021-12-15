using namespace std;
#include<bits/stdc++.h>
void compute(vector<vector<int>>& all_cases){
    vector<int> odd;
    vector<int> even;
    for(int i=0;i<all_cases.size();i++){
        for(int j=0;j<all_cases[i].size();j++){
            if(all_cases[i][j]%2==0) even.push_back(all_cases[i][j]);
            else odd.push_back(all_cases[i][j]);
        }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
     for(int idx=0;idx<all_cases[i].size();idx++){
         if(idx%2==0) all_cases[i][idx]=even[idx/2];
         else all_cases[i][idx]=odd[idx/2];
     }
     int position=-1;
     for(int idx=1;idx<all_cases[i].size();idx++){
          if(all_cases[i][idx]<all_cases[i][idx-1]) {
              position=idx-1;
              break;
          }
     }
     if(position==-1) printf("Case #%d: OK\n",i+1);
     else {
         printf("Case #%d: %d\n",i+1,position);
     }
    }
}
int main(){
    long total_test_cases;
    scanf("%ld",&total_test_cases);

    vector<vector<int>> all_cases;
    long int size,element;

    for( long i=0;i<total_test_cases;i++){
        scanf("%ld",&size);
        vector<int> sample;
        for(long j=0;j<size;j++){
           scanf("%ld",&element);
           sample.push_back(element);  
        }
        all_cases.push_back(sample);
    }
    compute(all_cases);
    getchar();
    return 0;
}