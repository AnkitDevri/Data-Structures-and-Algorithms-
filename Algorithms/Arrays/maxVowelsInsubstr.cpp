using namespace std;
#include<bits/stdc++.h>
bool isVowel(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' ||
                   x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' ||
                   x == 'O' || x == 'U')
       return true;
    else
       return false;
}
 int getMaxVow(string input,int k){
     int size=input.length();
     int count=0,MAX=0;
     for(int i=0;i<k;i++){
        if(isVowel(input[i]))
         count++;
     }
     MAX=count;

     for(int i=k;i<size;i++){
       if(isVowel(input[i]))
         count++;
      if(isVowel(input[i-k]))
         --count;

        MAX=max(MAX,count);
     }
     return MAX;
 }
int main(){
    int k;
    string input;
    getline(cin,input);
    cin>>k;
    cout<<getMaxVow(input,k);
    getchar();
    return 0;
}