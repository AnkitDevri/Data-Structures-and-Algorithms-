using namespace std;
#include<bits/stdc++.h>
 bool answer(vector<int> deck){
   unordered_map <int,int> freq;
   for(int i=0;i<deck.size();i++)
    freq[deck[i]]++;
   int gcd=0;
   for(auto it:freq){
    if(gcd==0)
     gcd=it.second;
    else
     gcd=__gcd(gcd,it.second);
   }
   if(gcd>=2)
    return true;
    else
    return false;
 }
int main(){
    int total,element;
    cin>>total;
    vector<int> deck(total);
    for(int i=0;i<deck.size();i++){
      cin>>element;
      deck[i]=element;
    }
    cout<<answer(deck);  
    getchar();
    return 0;
}