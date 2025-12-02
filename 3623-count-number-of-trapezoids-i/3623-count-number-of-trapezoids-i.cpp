class Solution {
public:
#define ll long long
    int countTrapezoids(vector<vector<int>>& pts) {
        const int mod = 1e9 + 7;
        map<int, int> freq;

        for (auto& p : pts) {
            freq[p[1]]++;
        }

        vector<ll> combs;
        for (auto& [y, c] : freq) {
            if (c >= 2) {
                combs.push_back(1LL * c * (c - 1) / 2);
            }
        }

        ll s = accumulate(combs.begin(), combs.end(), 0LL), ans = 0;
        for (int i = 0; i < combs.size(); ++i) {
            s -= combs[i];
            ans = (ans + combs[i] * s % mod) % mod;
        }

        return ans;
    }
};