class Solution {
public:
    int lis(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> lis;
        lis.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (lis.back() < nums[i]) {
                lis.push_back(nums[i]);
            } else {
                int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[idx] = nums[i];
            }
        }
        return lis.size();
    }

    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            vector<int> temp;
            for (int num : nums) {
                if (num & (1 << i)) temp.push_back(num);
            }
            ans = max(ans, lis(temp));
        }
        return ans;
    }
};
