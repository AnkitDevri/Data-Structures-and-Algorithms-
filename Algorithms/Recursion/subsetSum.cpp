using namespace std;
#include<bits/stdc++.h>
  int getTotalSubset(vector<int>& set,int& SUM,int sum,int index){
      if(index==set.size() && sum==SUM)
       return 1;
      else if(index==set.size())
       return 0;

       return getTotalSubset(set,SUM,sum,index+1)+getTotalSubset(set,SUM,sum+set[index],index+1);
  }
int main(){
    int n,ele;
    vector<int> set;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ele;
        set.push_back(ele);
    }
    int sum;
    cin>>sum;
    cout<<getTotalSubset(set,sum,0,0);
    getchar();
    return 0;
}