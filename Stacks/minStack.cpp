using namespace std;
#include <bits/stdc++.h>
class minStackNode {
    public:
    int data; 
    int min;
    minStackNode *prev_node;

    minStackNode(int val){
        this->data = val;
        this->min = val;
        this->prev_node = nullptr;
    }
};
class MinStack {
   minStackNode* top_node;
public:
 MinStack(){
     this->top_node = new minStackNode(INT_MAX);
 }
 MinStack(int val){
    this->top_node = new minStackNode(val);
}
void push( int val){
    minStackNode *temp = new minStackNode(val);
    if( this->getMin() > val) temp->min = val;
    else temp->min = this->getMin();

    temp->prev_node = this->top_node;
    this->top_node = temp;
}
void pop(){
    minStackNode *temp = this->top_node;
    this->top_node = top_node->prev_node;
    delete temp;
}

int top (){
    return top_node->data;
}

int getMin(){
    return top_node->min;
}

};
int main(){
    MinStack m;
    m.push(-2);
    m.push(0);
    m.push(-1);
    cout<< m.top();
    cout<< m.getMin();
    m.pop();
    cout<< m.top();
    cout<< m.getMin();
    getchar();
    return 0;
}