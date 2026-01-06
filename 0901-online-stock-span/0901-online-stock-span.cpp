class StockSpanner {
public:
    stack<int> st;
    vector<int> v;

    StockSpanner() {}

    int next(int price) {
        v.push_back(price);

        while (!st.empty() && v[st.top()] <= price) {
            st.pop();
        }

        int ans;
        if (st.empty())
            ans = v.size();
        else
            ans = v.size() - st.top() - 1;

        st.push(v.size() - 1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */