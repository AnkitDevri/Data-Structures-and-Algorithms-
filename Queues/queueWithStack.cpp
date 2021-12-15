using namespace std;
#include <bits/stdc++.h>
class Q{
    public:
    stack <int> pop_stack;
    stack <int> push_stack;
    void revitalize(){
        while( !push_stack.empty()){
            int x = push_stack.top();
            push_stack.pop();
            pop_stack.push(x);
        }

    }
    void push( int val){
        if(pop_stack.empty()){
            revitalize();
        }
        push_stack.push(val);
    }

    int pop(){
       if( pop_stack.empty()) {
           revitalize();
       }
        int x = pop_stack.top();
        pop_stack.pop();
        return x;
    }

    int peek (){
        if( pop_stack.empty()) revitalize();
        return pop_stack.top();
    }

    bool empty(){
        return (push_stack.empty() && pop_stack.empty());
    }
};
int main(){
    Q s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.peek();
    s.pop();
    cout<<s.peek();
    s.pop();
    cout<<s.peek();
    return 0;
}