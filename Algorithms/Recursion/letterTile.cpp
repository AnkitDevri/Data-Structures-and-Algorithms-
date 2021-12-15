using namespace std;
#include<bits/stdc++.h>
 void permutations(string& a,int index,int& count){
   if(index==a.size()){
     return;
   }
   int freq[26]={0};
   for(int i=index;i<a.size();i++){
   if(freq[a[i]-'A']==0){
      count++;
     swap(a[index],a[i]);
     permutations(a,index+1,count);
     swap(a[index],a[i]);
    
    }
    freq[a[i]-'A']++;
   }
 }
int main(){
  string sample;
  cin>>sample;
  int count=0;
  permutations(sample,0,count);
  cout<<count;
  getchar();
  return 0;
}