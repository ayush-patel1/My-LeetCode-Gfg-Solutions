class Solution {
public:
    void compute(vector<int>& nse, vector<int>& pse, vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n), pse(n, -1);
        compute(nse, pse, heights);
        int max_area=0;
        for (int i = 0; i < n; i++) {
            int w=nse[i]-pse[i]-1;
            max_area=max(max_area,heights[i]*w);
        }
        return max_area;
    }
};