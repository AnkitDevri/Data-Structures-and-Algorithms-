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
int main() {
    stack <int> s;
    int size, ele;
    scanf("%d", &size);
    
    for ( int i = 0; i < size; i++) {
        scanf("%d", &ele);
        s.push(ele);
    }
    
    scanf("%d", &ele);
    push_in_bottom( s, ele);
    
    PrintStack(s);
    
    getchar();
    return 0;
}