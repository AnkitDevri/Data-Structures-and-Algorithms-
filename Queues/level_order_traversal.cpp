using namespace std;
#include <bits/stdc++.h>
/*
void level_order_traversal(queue <int>& nums,int startNum, int& endNum){
    startNum = startNum*10;
    if(startNum >= endNum) return;
    int i = 0;
    while (i<3) {
        i++;
        startNum++;
        nums.push(startNum);
        level_order_traversal(nums,startNum, endNum);
    }
    
}

void displayNums( queue<int>& nums){
    while ( !nums.empty()){
        cout<< nums.front()<<" ";
        nums.pop();
    }
}
*/
 void printRemaining(queue<int>& nums){
     while(!nums.empty()) {
         cout<<nums.front()<<" ";
         nums.pop();
     }
 }

 void level_order_traversal( int upperLimit){
   queue<int> nums;
   int numOfChildren = 3;
   int child = 0;
   int distBetweenNextNums = 10;

   while (child < upperLimit){
        int limit = child + numOfChildren;
        while(child < limit && child <= upperLimit ) nums.push(++child);
        child = nums.front()*distBetweenNextNums;    
        cout<< nums.front()<<" ";
        nums.pop();
   }

   printRemaining(nums);              // printing the remaining elements of the queue
 }
int main(){
    int number;
    //queue <int> sortedNums;
    scanf("%d",&number);
  //  level_order_traversal(sortedNums, 0 , number);
   // displayNums(sortedNums);
   level_order_traversal(number);
    return 0;
}