using namespace std;
#include <bits/stdc++.h>
class minStackNode {
    public:
    int data; 
    minStackNode *prev_node;

    minStackNode(int val){
        this->data = val;
        this->prev_node = nullptr;
    }
};
class MinStack {
   minStackNode* top_node;
   int minm_val;
public:
 MinStack(){
     this->top_node = new minStackNode(1e7);
     minm_val = 1e7;
 }
 MinStack(int val){
    this->top_node = new minStackNode(val);
}
void push( int val){
    minStackNode *temp = new minStackNode(val);
    if( minm_val > val){
         temp->data = (2*val)-minm_val;
         minm_val = val;
    }
    else temp->data = val;

    temp->prev_node = this->top_node;
    this->top_node = temp;
}
void pop(){
    minStackNode *temp = this->top_node;
    if(top_node->data < minm_val ) {
        minm_val = (2*minm_val)-top_node->data;
    }
    this->top_node = top_node->prev_node;
    delete temp;
}

int top (){
    return top_node->data;
}

int getMin(){
    return minm_val;
}

};
int main(){
    MinStack m;
    m.push(-2);
    cout<<m.top();
    cout<<m.getMin();
    m.push(0);
    cout<<m.top();
    cout<<m.getMin();
    m.push(-3);
    cout<< m.top();
    cout<< m.getMin();
    m.pop();
    cout<< m.top();
    cout<< m.getMin();
    getchar();
    return 0;
}