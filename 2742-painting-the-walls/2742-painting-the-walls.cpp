class Solution {
public:
    vector<vector<int>> dp;

    int solve(int rem, int idx, vector<int>& cost, vector<int>& time) {
        if (rem <= 0) return 0;
        if (idx == cost.size()) return 1e9;

        if (dp[idx][rem] != -1) return dp[idx][rem];

        int take = cost[idx] + solve(rem - time[idx] - 1, idx + 1, cost, time);
        int notTake = solve(rem, idx + 1, cost, time);

        return dp[idx][rem] = min(take, notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(n, 0, cost, time);
    }
};