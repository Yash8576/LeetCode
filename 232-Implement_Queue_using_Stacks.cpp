class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {

    }   
    void push(int x) {
        st1.push(x);
    }
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                int x = st1.top();
                st1.pop();
                st2.push(x);
            }
        }
        int y = st2.top();
        st2.pop();
        return y;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                int x = st1.top();
                st1.pop();
                st2.push(x);
            }
        }
        return st2.top();
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()) return true;
        else return false;
    }
};
