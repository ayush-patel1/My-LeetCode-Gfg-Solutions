#define ll long long
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const ll MOD = 1e9 + 7;
        vector<int> cnt(32, 0);

        for (int x : nums) {
            for (int b = 0; b < 32; b++) {
                if (x & (1LL << b)) cnt[b]++;
            }
        }

        ll ans = 0;

        while (k--) {
            ll x = 0;

            for (int b = 0; b < 32; b++) {
                if (cnt[b] > 0) {
                    x |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + x * x % MOD) % MOD;
        }

        return ans;
    }
};
