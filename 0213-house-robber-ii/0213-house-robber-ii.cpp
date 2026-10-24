class Solution {
public:
    vector<int> dp;

    int solve(int idx, int n, vector<int>& nums) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solve(idx + 2, n, nums);
        int notTake = solve(idx + 1, n, nums);

        return dp[idx] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        dp.assign(n, -1);
        int op1 = solve(0, n - 1, nums);

        dp.assign(n, -1);
        int op2 = solve(1, n, nums);

        return max(op1, op2);
    }
};
