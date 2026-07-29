class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0, left = 0, right = m - 1, bot = n - 1;
        int tot = n * m, cnt = 0;
        vector<int> ans;

        while (cnt < tot) {
            for (int i = left; i <= right && cnt < tot; i++) {
                ans.push_back(matrix[top][i]);
                cnt++;
            }
            top++;

            for (int i = top; i <= bot && cnt < tot; i++) {
                ans.push_back(matrix[i][right]);
                cnt++;
            }
            right--;

            for (int i = right; i >= left && cnt < tot; i--) {
                ans.push_back(matrix[bot][i]);
                cnt++;
            }
            bot--;

            for (int i = bot; i >= top && cnt < tot; i--) {
                ans.push_back(matrix[i][left]);
                cnt++;
            }
            left++;
        }

        return ans;
    }
};