class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if ((totalSum + target) % 2 != 0 || totalSum < abs(target)) return 0;

        int sum = (totalSum + target) / 2;

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2; 
        else
            dp[0][0] = 1; 

        if (nums[0] != 0 && nums[0] <= sum)
            dp[0][nums[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= sum; tar++) {
                int notTaken = dp[ind - 1][tar];
                int taken = 0;
                if (nums[ind] <= tar)
                    taken = dp[ind - 1][tar - nums[ind]];
                dp[ind][tar] = notTaken + taken;
            }
        }

        return dp[n - 1][sum];
    }
};