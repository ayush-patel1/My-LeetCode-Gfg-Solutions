class MyQueue {
public:
    stack<int> st;

    MyQueue() {
    }

    void push(int x) {
        vector<int> t;

        while (!st.empty()) {
            t.push_back(st.top());
            st.pop();
        }

        st.push(x);

        while (!t.empty()) {
            st.push(t.back());
            t.pop_back();
        }
    }

    int pop() {
        if (st.empty()) return -1;
        int x = st.top();
        st.pop();
        return x;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */