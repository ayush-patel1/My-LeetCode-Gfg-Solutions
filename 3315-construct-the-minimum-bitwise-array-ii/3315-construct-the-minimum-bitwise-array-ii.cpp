class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if ((nums[i] & 1) == 0) {
                ans[i] = -1;
            } else {
                int bit = 0;
                while (((nums[i] >> bit) & 1) == 1) {
                    bit++;
                }
                ans[i] = nums[i] - (1 << (bit - 1));
            }
        }

        return ans;
    }
};