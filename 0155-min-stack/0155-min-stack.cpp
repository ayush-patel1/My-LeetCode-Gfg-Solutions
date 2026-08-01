class MinStack {
public:
stack<pair<int,int>>st;
//{value,min_value(till now)}
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push({value,value});
            return;
        }
        int mn=st.top().second;
        st.push({value,min(mn,value)});
    }
    
    void pop() {
        if(!st.empty()){
            return st.pop();
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */