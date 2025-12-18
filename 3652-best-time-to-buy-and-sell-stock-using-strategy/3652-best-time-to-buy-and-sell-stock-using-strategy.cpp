class Solution {
public:
    using ll = long long;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll> prefix(n), sell(n);
        ll ori = 0;
        for (int i = 0; i < n; i++) {
            ori += 1LL * prices[i] * strategy[i];
            prefix[i] = ori;
        }
        sell[0] = prices[0];
        for (int i = 1; i < n; i++) sell[i] = sell[i-1] + prices[i];

        int half = k / 2;
        if (half == 0) return ori;

        ll max_sum = ori;
        for (int i = half; i <= n - half; i ++) {
            ll l = (i - half - 1 >= 0) ? prefix[i - half - 1] : 0;
            ll r = (i + half - 1 < n - 1) ? (prefix[n - 1] - prefix[i + half - 1]) : 0;
            ll m = (i - 1 >= 0) ? (sell[i + half - 1] - sell[i - 1]) : sell[i + half - 1];
            max_sum = max(max_sum, l + r + m);
        }
        return max_sum;
    }
};
