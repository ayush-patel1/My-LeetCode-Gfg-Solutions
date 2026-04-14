class Solution {
public:
#define ll long long

    ll dp[105][105];

    ll solve(int i, int j, vector<int>& r, vector<vector<int>>& f){
        if(i >= r.size()) return 0;
        if(j >= f.size()) return 1e18;

        if(dp[i][j] != -1) return dp[i][j];

        ll ans = solve(i, j + 1, r, f);

        ll pos = f[j][0];
        ll lim = f[j][1];

        ll sum = 0;

        for(int k = 1; k <= lim && i + k - 1 < r.size(); k++){
            sum += abs(r[i + k - 1] - pos);
            ans = min(ans, sum + solve(i + k, j + 1, r, f));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        sort(r.begin(), r.end());
        sort(f.begin(), f.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, r, f);
    }
};