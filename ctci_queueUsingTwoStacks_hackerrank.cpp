#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

/*
All pushes are done in the first stack. Hence the first element will be at the bottom. To retrieve it use the 
second stack to move all the elements and have it at the top. The order is mantained so, the second element will be
below the first one in the second stack, and so on. If the stack2 is empty, the first element is still on the first stack
(or does not exist), so move around all of them to retrive it.
*/


class MyQueue {
  
    public:
        stack<int> st1, st2;   
        void push(int x) {
            st1.push(x);                   
        }

        void pop() {
            if(!st2.empty()){
                st2.pop();
                return;
            }
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }

        int top() {
            if(!st2.empty()){
                return st2.top();
            }
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.top() << endl;
    }
    
    return 0;
}
