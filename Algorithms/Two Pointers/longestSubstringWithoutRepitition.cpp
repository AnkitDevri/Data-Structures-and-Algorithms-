using namespace std;
#include<bits/stdc++.h>

string get_longest_substring(string& input){
 vector<int> frequency(256,0);
 int pointer_answer1=0;
 int pointer_answer2=0;
 int pointer_1=0;
 int pointer_2=0;
 int i=pointer_1;

 while(i<input.size()){
     if(i+1==input.size()){
      if(pointer_2-pointer_1>pointer_answer2-pointer_answer1){
            pointer_answer1=pointer_1;
            pointer_answer2=pointer_2;
        }
     }
     if(frequency[input[i]]==0){
         pointer_2++;
         frequency[input[i]]++;
         i++;
     }
     else{
        if(pointer_2-pointer_1>pointer_answer2-pointer_answer1){
            pointer_answer1=pointer_1;
            pointer_answer2=pointer_2;
        }
        frequency[input[pointer_1]]--; 
        pointer_1++;
     }
 }
 return input.substr(pointer_answer1,pointer_answer2);
}
int main(){
    string input;
    cin>>input;
    cout<<get_longest_substring(input);
    getchar();
    return 0;
}