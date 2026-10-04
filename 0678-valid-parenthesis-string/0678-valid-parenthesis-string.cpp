class Solution {
public:
    bool solve(int idx, int cur, string &s, vector<vector<int>>& dp) {
        if(cur < 0) return false;

        if(idx >= s.size())
            return cur == 0;

        if(dp[idx][cur] != -1) return dp[idx][cur];

        bool ans = false;
        if(s[idx] == '(') ans = solve(idx + 1, cur + 1, s, dp);
        else if(s[idx] == ')') ans = solve(idx + 1, cur - 1, s, dp);
        else {
            ans = solve(idx + 1, cur + 1, s, dp) ||
                  solve(idx + 1, cur - 1, s, dp) ||
                  solve(idx + 1, cur, s, dp);
        }

        return dp[idx][cur] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, 0, s, dp);
    }
};