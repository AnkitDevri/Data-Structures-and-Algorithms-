using namespace std;
#include<bits/stdc++.h>
 bool isPerm(string s1,string s2){
     string sort1=s1;
     int size=s1.length();
     sort(sort1.begin(),sort1.end());

     if(s2.length()<size)
      return false;

      else{
         bool answer=false;
         for(int i=0;i<=s2.length()-size;i++){
          string temp=s2.substr(i,size);
         sort(temp.begin(),temp.end());
         if(!sort1.compare(temp)){
             answer=true;
             break;
         }
             }
      return answer;
      }
 }
int main(){
    
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<isPerm(s1,s2);
    getchar();
    return 0;
}