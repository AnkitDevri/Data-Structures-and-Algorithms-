#include<iostream>
#include<set>
#include<conio.h>
using namespace std;

int main(){
    set<int> buildings={};
    set<int> pair;
    int size,element;
    cin>>size;
    for(auto i=0;i<size;i++){
        cin>>element;
        buildings.insert(element);
    }
    auto i=buildings.begin();
    while(i!=buildings.end()){
        cout<<*i;
        i++;
    }
    getch();
    return 0;
}