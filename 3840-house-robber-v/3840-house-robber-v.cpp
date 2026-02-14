class Solution {
public:
#define ll long long
    vector<ll> dp;
    int n;

    ll solve(vector<int>& nums, vector<int>& colors, int idx) {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        ll take = nums[idx];
        if (idx + 1 < n && colors[idx] == colors[idx + 1])
            take += solve(nums, colors, idx + 2);
        else
            take += solve(nums, colors, idx + 1);

        ll notTake = solve(nums, colors, idx + 1);

        return dp[idx] = max(take, notTake);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        n = nums.size();
        dp.assign(n, -1);
        return solve(nums, colors, 0);
    }
};
