class Solution {
public:
    const int mod = 1e9+7;
    #define ll long long

    int numSub(string s) {
        int n = s.size();
        ll ans = 0, cur = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cur++;
            } else {
                ans = (ans + (cur * (cur + 1) / 2) % mod) % mod;
                cur = 0;
            }
        }

        if (cur) {
            ans = (ans + (cur * (cur + 1) / 2) % mod) % mod;
        }

        return ans;
    }
};
