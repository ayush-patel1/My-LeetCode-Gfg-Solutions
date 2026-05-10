class Solution {
public:
#define ll long long

    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        ll sum = 0;
        unordered_set<ll> st;

        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            int mn = cur;

            for (int j = 1; j * j <= cur; j++) {
                if (cur % j) continue;

                int t = cur / j;

                if (j != cur && st.find(j) != st.end()) {
                    mn = min(mn, j);
                }

                if (t != cur && st.find(t) != st.end()) {
                    mn = min(mn, t);
                }
            }

            sum += mn;
            st.insert(cur);
        }

        return sum;
    }
};