class Solution {
public:
    #define ll long long

    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<ll, ll>> v;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            sort(s.rbegin(), s.rend());

            ll mx = stoll(s);
            ll gain = mx - nums[i];

            v.push_back({gain, mx});
            ans += nums[i];
        }

        sort(v.rbegin(), v.rend());

        for (int i = 0; i < k; i++) {
            ans += v[i].first;
        }

        return ans;
    }
};