using namespace std;
#include <bits/stdc++.h>
class MyStack {
public:
    queue <int> pushQueue;
    queue <int> popQueue;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    void resetPopQueue(){
        if(popQueue.empty()) {
            resetPushQueue();
            return;
        }
        int element = popQueue.front();
        popQueue.pop();
        resetPopQueue();
        popQueue.push(element);
    }
    void resetPushQueue(){
        if( pushQueue.empty()) return;
        int element = pushQueue.front();
        pushQueue.pop();
        resetPushQueue();
        popQueue.push(element);
    }
    /** Push element x onto stack. */
    void push(int x) {
        pushQueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
         if(!pushQueue.empty()) resetPopQueue();
         int element = popQueue.front();
         popQueue.pop();
         return element;
    }
    
    /** Get the top element. */
    int top() {
         if(pushQueue.empty()) return popQueue.front();
         else return pushQueue.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return pushQueue.empty() && popQueue.empty();
    }
};


int main(){
    MyStack m;
    m.push(1);
    cout<< m.top();
    m.push(2);
    cout<< m.top();
    m.push(3);
    cout<< m.top();
    m.pop();
    cout<<m.top();
    m.pop();
    cout<<m.top();
    return 0;
}