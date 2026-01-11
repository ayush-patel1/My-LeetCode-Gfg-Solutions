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
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int w = nse[i] - pse[i] - 1;
            max_area = max(max_area, heights[i] * w);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size(), maxRect = 0;
        vector<int> heights(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxRect = max(maxRect, largestRectangleArea(heights));
        }
        return maxRect;
    }
};