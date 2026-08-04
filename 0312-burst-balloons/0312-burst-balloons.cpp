class Solution {
public:
    vector<vector<int>> dp;
    int solve(int s, int e, vector<int> &nums) {
        if (s > e) return 0;
        if (dp[s][e] != -1) return dp[s][e];

        int max_ans = 0;
        for (int k = s; k <= e; k++) {
            int coins = nums[s - 1] * nums[k] * nums[e + 1]
                        + solve(s, k - 1, nums)
                        + solve(k + 1, e, nums);
            max_ans = max(max_ans, coins);
        }
        return dp[s][e] = max_ans;
    }

    int maxCoins(vector<int> &nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(1, n - 2, nums);
    }
};