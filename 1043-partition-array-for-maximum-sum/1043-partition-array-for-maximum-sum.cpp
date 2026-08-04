class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& arr, int k, int idx) {
        if (idx >= arr.size()) return 0;

        if (dp[idx] != -1) return dp[idx];

        int mx = 0;
        int res = 0;

        for (int i = idx; i < min(idx + k, (int)arr.size()); i++) {
            mx = max(mx, arr[i]);
            res = max(res, mx * (i - idx + 1) + solve(arr, k, i + 1));
        }

        return dp[idx] = res;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.assign(n, -1);
        return solve(arr, k, 0);
    }
};