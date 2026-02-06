class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mx = 0;

        for(int i = 0; i < n; i++){
            int ub = upper_bound(nums.begin() + i, nums.end(), 1LL * nums[i] * k) - nums.begin();
            mx = max(mx, ub - i);
        }
        return n - mx;
    }
};
