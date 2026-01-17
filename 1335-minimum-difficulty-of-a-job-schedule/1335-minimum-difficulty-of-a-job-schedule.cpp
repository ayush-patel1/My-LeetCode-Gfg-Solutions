class Solution {
public:
    int n;
    vector<vector<unordered_map<int,int>>> dp;

    int solve(int idx, vector<int>& jd, int d, int curr){
        if(n - idx < d) return 1e9;

        if(d == 0){
            if(idx == n) return 0;
            return 1e9;
        }

        if(idx == n) return 1e9;

        if(dp[idx][d].count(curr))
            return dp[idx][d][curr];

        curr = max(curr, jd[idx]);

        int op1 = curr + solve(idx + 1, jd, d - 1, 0);
        int op2 = solve(idx + 1, jd, d, curr);

        return dp[idx][d][curr] = min(op1, op2);
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(n < d) return -1;

        dp.assign(n, vector<unordered_map<int,int>>(d + 1));
        return solve(0, jobDifficulty, d, 0);
    }
};
