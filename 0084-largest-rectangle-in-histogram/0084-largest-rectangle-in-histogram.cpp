class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int cur = (i == n ? 0 : h[i]);

            while (!st.empty() && h[st.top()] > cur) {
                int height = h[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }
};
