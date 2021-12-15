using namespace std;
#include<bits/stdc++.h>
vector<vector<char>> keypad(10);

void printC(string temp,string& digicode,int track){
 if(track==digicode.size()){
     cout<<temp<<endl;
     return;
 }
 for(int i=0;i<keypad[digicode[track]-'0'].size();i++){
  printC(temp+keypad[digicode[track]-'0'][i],digicode,track+1);
 }
  
}

int main(){
    keypad[0]=keypad[1]={};
    for(int i=2;i<7;i++)
     keypad[i]={char('a'+3*(i-2)),char('b'+3*(i-2)),char('c'+3*(i-2))};
     keypad[7]={'p','q','r','s'};
     keypad[8]={'t','u','v'};
     keypad[9]={'w','x','y','z'};

  /*  for(int i=0;i<10;i++){
     for(int j=0;j<keypad[i].size();j++)
       cout<<keypad[i][j]<<" ";
     cout<<endl;
    }
*/
    string temp="";
    string digicode;
    cin>>digicode;
    printC(temp,digicode,0);

    getchar();
    return 0;

}