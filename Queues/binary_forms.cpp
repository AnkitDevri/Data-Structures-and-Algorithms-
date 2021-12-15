using namespace std;
#include <bits/stdc++.h>
void printBinaryForms(vector <string>& binaryForms){
    for ( auto i : binaryForms) cout<<i<<" ";
}

void BinaryForms(int number){
    vector <string> binaryNums;
    queue <string> forLevelOrder;
    string startNum = "1";
    int base = 2;

    forLevelOrder.push(startNum);
    binaryNums.push_back(startNum);

    while( binaryNums.size() < number ){
        int i = 0;
        while ( i < base && binaryNums.size() < number)
        {
            forLevelOrder.push(startNum + to_string(i));
            binaryNums.push_back(startNum + to_string(i));
            i++;
        }
        forLevelOrder.pop();
        startNum = forLevelOrder.front();  
    }

    printBinaryForms(binaryNums);
}
int main() {
    int number;
    scanf("%d", &number);
    BinaryForms(number);
    return 0;
}