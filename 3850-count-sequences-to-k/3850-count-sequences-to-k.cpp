class Solution {
    using ll = long long;
    
    map<vector<ll>, ll> dp;

    pair<ll,ll> resolve(ll num, ll den) {
        ll g = __gcd(num, den);
        num /= g;
        den /= g;
        return {num, den};
    }

    ll solve(vector<int>& a, ll k, ll pos, ll num, ll den) {
        int n = a.size();

        auto p = resolve(num, den);
        num = p.first;
        den = p.second;

        if (pos == n) {
            return (num == k && den == 1);
        }

        vector<ll> key = {pos, num, den};
        if (dp.count(key)) return dp[key];

        ll ans = 0;

        ans += solve(a, k, pos + 1, num, den);
        ans += solve(a, k, pos + 1, num * a[pos], den);
        ans += solve(a, k, pos + 1, num, den * a[pos]);

        return dp[key] = ans;
    }

public:
    int countSequences(vector<int>& a, long long k) {
        dp.clear();
        return solve(a, k, 0, 1, 1);
    }
};