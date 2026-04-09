class MinStack {
public:
    vector<pair<int,int>> st;
    int tp;

    MinStack() {
        st.resize(1e5);
        tp = -1;
    }
    
    void push(int val) {
        if(tp != -1){
            auto node = st[tp];
            st[++tp] = {val, min(val, node.second)};
        }else{
            st[++tp] = {val, val};
        }
    }
    
    void pop() {
        tp--;
    }
    
    int top() {
        return st[tp].first;
    }
    
    int getMin() {
        return st[tp].second;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */