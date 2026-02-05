class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                int newIdx = (i - abs(nums[i]) % n + n) % n;
                result[i] = nums[newIdx];
            } else if (nums[i] > 0) {
                int newIdx = (i + nums[i]) % n;
                result[i] = nums[newIdx];
            }
        }

        return result;
    }
};
