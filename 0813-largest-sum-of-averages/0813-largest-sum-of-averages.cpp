class Solution {
public:
    vector<vector<double>> dp;
    vector<int> pre;
    int n;

    double solve(int idx, int k, vector<int>& nums) {
        if (idx >= n && k > 1) return -1e9;

        if (k == 1) {
            return (double)(pre[n-1] - (idx > 0 ? pre[idx-1] : 0)) / (n - idx);
        }

        if (dp[idx][k] != -1) return dp[idx][k];

        double ans = 0;

        for (int i = idx; i < n; i++) {
            double curr = (double)(pre[i] - (idx > 0 ? pre[idx-1] : 0)) / (i - idx + 1);
            ans = max(ans, curr + solve(i + 1, k - 1, nums));
        }

        return dp[idx][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        dp.assign(n, vector<double>(k + 1, -1));
        pre.resize(n);

        pre[0] = nums[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i-1] + nums[i];

        return solve(0, k, nums);
    }
};