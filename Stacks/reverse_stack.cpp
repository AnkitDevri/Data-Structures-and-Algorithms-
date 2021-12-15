using namespace std;
#include <bits/stdc++.h>
void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
 
    int x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

void push_in_bottom ( stack <int>& s, int ele) {
    if ( s.empty() ) {
        s.push(ele);
        return;
    }
    int a = s.top();
    s.pop();
    push_in_bottom( s, ele);
    s.push(a);

}

void reverse_stack ( stack <int>& s) {
     if(s.size()>0)
    {
         
        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        char x = s.top();
        s.pop();
        reverse_stack(s);
         
        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        push_in_bottom(s,x);
    }
}
int main() {
    stack <int> s;
    int size, ele;
    scanf("%d", &size);
    
    for ( int i = 0; i < size; i++) {
        scanf("%d", &ele);
        s.push(ele);
    }
    
   reverse_stack(s);
    
    PrintStack(s);
    
    getchar();
    return 0;
}