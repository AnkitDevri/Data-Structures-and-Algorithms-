#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 int primeDetect(int n){
    if(n<2 || (!(n&1) && n!=2))
        return 0;
    for(int i=3; i*i<=n; i+=2){
        if(!(n%i))
            return 0;
    }
    return 1;
}

int main() {
    int size,countneg=0;
    int length=0,element;
    cin>>size;
  vector<int> subarray(size,0);
    vector<int> minus;
    vector<int> lengtha;
    for(int i=0;i<size;i++){
       cin>>element;
       subarray[i]=element;  
    }
  for(int i=0;i<size;i++){
      if(primeDetect(subarray[i]==1)){
          i++;
         for(;primeDetect(subarray[i])!=1;i++){
            length++;
             if(subarray[i]<0)
                 countneg++;  
         }
         minus.push_back(countneg);
         lengtha.push_back(length);
      }
   
  }
   int index= std::distance(lengtha.begin(),min_element(lengtha.begin(),lengtha.end()));
   int index2= std::distance(minus.begin(),min_element(minus.begin(),minus.end()));
   cout<<lengtha[index2];
    return 0;
}