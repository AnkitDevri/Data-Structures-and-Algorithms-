using namespace std;
#include<iostream>
#include<conio.h>
#include<string>

void printDups(string str){
int arr[256]={0};
for(int i=0;i<str.length();i++)
   arr[str[i]]++;

for(int i=0;i<256;i++){
    if(arr[i]>1)
    cout<<(char)i;
}
}
int main(){
    string str;
    getline(cin,str);
    printDups(str);
    getch();
    return 0;
}