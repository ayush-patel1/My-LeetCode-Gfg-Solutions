class Solution {
public:
#define ll long long
    long long getDescentPeriods(vector<int>& prices) {
        ll n = prices.size();
        ll i = 0;
        vector<ll> m;

        while (i < n) {
            ll cnt = 1;
            ll prev = prices[i];
            i++;
            while (i < n && prev - prices[i] == 1) {
                cnt++;
                prev = prices[i];
                i++;
            }
            m.push_back(cnt);
        }

        ll sm = accumulate(m.begin(), m.end(), 0LL);
        ll ans = 0;
        for (int i = 0; i < m.size(); i++) {
            ans += 1LL * m[i] * (m[i] + 1) / 2;
        }
        return ans;
    }
};
