class Solution {
public:
    using ll = long long;
    vector<ll> dp;

    ll solve(int n)
    {
        if(n <= 1) return 0;
        if(dp[n] != -1) return dp[n];

        ll cost = 1e18;

        for(int i = 1; i <= n/2; i++)
        {
            ll x = i;
            ll y = n - i;

            ll cur = x*y + solve(x) + solve(y);
            cost = min(cost, cur);
        }

        return dp[n] = cost;
    }

    int minCost(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};