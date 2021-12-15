using namespace std;
#include <bits/stdc++.h>
bool search ( unordered_map <int,int>& h, int a){
    if(h.find(a) == h.end()) return false;
    return true;
}
int main() {
    int size, element;
    scanf( "%d", &size);
    unordered_map <int,int> Htable;
    for (int i = 0; i < size; i++){
        scanf( "%d", &element);
        Htable[element] = 0;
    }

    
    getchar();
    return 0;
}