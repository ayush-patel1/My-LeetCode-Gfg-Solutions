class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0, q = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return false;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                p = i;
                break;
            }
        }

        for (int i = p; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                q = i;
                break;
            }
        }
        for (int i = q; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }

        if (p && q)
            return true;

        return false;
    }
};