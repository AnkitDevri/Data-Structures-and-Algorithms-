using namespace std;
#include<bits/stdc++.h>
class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
      vector<int> ans;
      unordered_set <int> un;
      int ptr1 = 0;
      int ptr2 = max(m,n) -1;
      if(m>n){
          while(ptr1<=ptr2){
              un.insert(arr1[ptr1]);
              un.insert(arr2[ptr2]);
              ptr1++;
              ptr2--;
          }
      }
      else{
          while(ptr1 <= ptr2){
            un.insert(arr2[ptr1]);
            un.insert(arr1[ptr2]);
              ptr1++;
              ptr2--;  
          }
      }
      for(auto i : un){
          ans.push_back(i);
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
};