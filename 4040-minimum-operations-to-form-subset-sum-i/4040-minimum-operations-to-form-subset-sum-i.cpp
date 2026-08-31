class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<pair<int,int>>> v;
    int n, sum;

    int solve(int i, int s) {
        if (s == sum) return 0;
        if (i == n) return 1e9;

        if (dp[i][s] != -1) return dp[i][s];

        int ans = solve(i + 1, s);

        for (auto [x, c] : v[i]) {
            if (s + x <= sum)
                ans = min(ans, c + solve(i + 1, s + x));
        }

        return dp[i][s] = ans;
    }

    int minOperations(vector<int>& nums, int target) {
        n = nums.size();
        sum = target;

        dp.assign(n, vector<int>(sum + 1, -1));
        v.resize(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i], c = 0;

            while (x <= sum) {
                v[i].push_back({x, c});
                if (x > sum / 2) break;
                x *= 2;
                c++;
            }

            x = nums[i];
            c = 0;

            while (x > 0) {
                x /= 2;
                c++;
                if (x == 0) break;
                v[i].push_back({x, c});
            }
        }

        int ans = solve(0, 0);
        return ans == 1e9 ? -1 : ans;
    }
};