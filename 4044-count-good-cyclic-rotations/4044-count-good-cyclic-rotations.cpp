class Solution {
public:
    #define ll long long

    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();

        vector<ll> pre(2 * n);
        pre[0] = nums[0];

        for (int i = 1; i < 2 * n; i++) {
            pre[i] = pre[i - 1] + nums[i % n];
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int m = i + n / 2 - 1;
            int e = i + n - 1;

            ll f = pre[m] - (i > 0 ? pre[i - 1] : 0);
            ll s = pre[e] - pre[m];

            if (f > s)
                cnt++;
        }

        return cnt;
    }
};