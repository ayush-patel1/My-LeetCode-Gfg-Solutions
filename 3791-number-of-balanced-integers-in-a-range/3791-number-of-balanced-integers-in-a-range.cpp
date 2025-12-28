#define ll long long
class Solution {
public:
    ll dp[17][100][100][2];

    ll f(int i, int odd, int even, bool tight, string &s) {
        if (i == s.length()) {
            return odd == even;
        }

        ll &res = dp[i][odd][even][tight];
        if (res != -1) return res;
        res = 0;

        int ub = tight ? s[i] - '0' : 9;

        for (int j = 0; j <= ub; j++) {
            bool nt = tight && (j == ub);
            if (i % 2)
                res += f(i + 1, odd + j, even, nt, s);
            else
                res += f(i + 1, odd, even + j, nt, s);
        }
        return res;
    }

    long long countBalanced(long long low, long long high) {
        string hi = to_string(high);
        string lo = to_string(low - 1);

        memset(dp, -1, sizeof(dp));
        ll ans = f(0, 0, 0, 1, hi);

        memset(dp, -1, sizeof(dp));
        ans -= f(0, 0, 0, 1, lo);

        return ans;
    }
};
