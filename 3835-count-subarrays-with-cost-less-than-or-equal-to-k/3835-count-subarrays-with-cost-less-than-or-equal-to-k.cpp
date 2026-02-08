class Solution {
public:
#define ll long long
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        multiset<ll> st;
        int l = 0;
        ll ans = 0;

        for (int r = 0; r < n; r++) {
            st.insert(nums[r]);

            while ((*prev(st.end()) - *st.begin()) * (r - l + 1) > k) {
                st.erase(st.find(nums[l]));
                l++;
            }

            ans += (r - l + 1);
        }
        return ans;
    }
};
