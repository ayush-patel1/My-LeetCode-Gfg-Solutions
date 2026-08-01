class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int left, int right) {
        if (left == right) return nums[left];
        if (dp[left][right] != -1) return dp[left][right];

        int leftScore = nums[left] - solve(nums, dp, left + 1, right);
        int rightScore = nums[right] - solve(nums, dp, left, right - 1);

        return dp[left][right] = max(leftScore, rightScore);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(nums, dp, 0, n - 1) >= 0;
    }
};