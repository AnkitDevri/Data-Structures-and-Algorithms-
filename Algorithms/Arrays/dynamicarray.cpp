#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    int lastanswer=0;
    vector<vector<int>> arr(queries.size(),vector<int>(n));
    vector<int>answer;
 for(int i=0; i<queries.size();i++){
    
         if(queries[i][0]==1){
             int cal=(queries[i][1]^lastanswer)%n;
             int element=queries[i][2];
             arr[cal].insert(arr[cal].end(),element);
         }
         else if(queries[i][0]==2){
             int cal=(queries[i][1]^lastanswer)%n;
             int element=queries[i][2];
        lastanswer=element%arr[cal].size();
        cout<<lastanswer;
        answer.push_back(lastanswer);
         }
     }
     return answer;
 }


 int main(){
     vector<int> answer;
     int size,element,i,j;
     cin>>size;
     vector<vector<int>> quer(size,vector<int>(3,0));
     for( i=0;i<size;i++){
      for( j=0;j<3;j++){
       cin>>element;
       quer[i][j]=element;
      }
     }
      
     answer=dynamicArray(size,quer);
     for(int i=0;i<answer.size();i++)
      cout<<answer[i];

     return 0;
 }
