using namespace std;
#include<bits/stdc++.h>
 void permutations(vector<string>& perms,string& a,int index){
   if(index==a.size()-1){
       perms.push_back(a);
       return;
   }
   for(int i=index;i<a.size();i++){
     // swap(a[index],a[i]);
     char temp=a[i];
      for(int j=i;j>=index;j--)           // right rotating the string and changing the index
        a[j]=a[j-1];
      a[index]=temp;
      permutations(perms,a,index+1);
     // swap(a[index],a[i]);
        temp=a[index];
      for(int j=index;j<=i;j++)          // backtracking by left rotatinng the sting and changing back the elements
        a[j]=a[j+1];
      a[i]=temp;
    
    }
 }
int main(){
    string a;
    cin>>a;
    vector<string> perms;
    permutations(perms,a,0);
    for(auto x : perms)
      cout<<x<<endl;
    getchar();
    return 0;
}