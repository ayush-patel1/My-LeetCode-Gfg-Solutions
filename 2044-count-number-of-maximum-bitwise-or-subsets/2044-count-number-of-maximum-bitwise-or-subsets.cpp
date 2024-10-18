class Solution {
public:
    int solve(vector<int>& nums, int req, int ind, int ans) {
        if (ind == nums.size()) {
            return ans == req ? 1 : 0;
        }
        int take = solve(nums, req, ind + 1, ans | nums[ind]);
        int notTake = solve(nums, req, ind + 1, ans);
        return take + notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int max_OR = 0;
        for (int num : nums) {
            max_OR |= num;
        }
        return solve(nums, max_OR, 0, 0);
    }
};
