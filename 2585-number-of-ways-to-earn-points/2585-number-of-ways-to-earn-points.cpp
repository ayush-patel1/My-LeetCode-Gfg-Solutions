class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<int>> dp;
    int n;

    int solve(int idx, int target, vector<vector<int>>& types){
        if(target == 0) return 1;
        if(idx >= n || target < 0) return 0;

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = solve(idx+1, target, types) % mod;

        int count = types[idx][0];
        int marks = types[idx][1];

        int take = 0;

        for(int i = 1; i <= count; i++){
            if(target - i*marks < 0) break;
            take = (take + solve(idx+1, target - i*marks, types)) % mod;
        }

        return dp[idx][target] = (take + notTake) % mod;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n = types.size();
        dp.assign(n, vector<int>(target+1, -1));
        return solve(0, target, types);
    }
};