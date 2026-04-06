class Solution {
public:
    int n;

    int rec(int i,int k,int r,vector<int>& nums,vector<vector<int>>& dp){
        if(k== 0) return 0;
        if(i > r){
            return 1e9;
        }
        if(dp[i][k] != -1) return dp[i][k];

        int ans = 1e9;

        int mx = max(nums[(i-1+n)%n], nums[(i+1)%n]);
        int op = max(0, mx + 1 - nums[i]);

        ans = min(ans, op + rec(i+2, k-1, r, nums, dp));
        ans = min(ans, rec(i+1, k, r, nums, dp));

        return dp[i][k] = ans;
    }

    int minOperations(vector<int>& nums, int k) {
        n = nums.size();
        if(k == 0) return 0;
        if(k > (n+1)/2) return -1;

        int ans = 1e9;

        vector<vector<int>> dp(n+2, vector<int>(k+1, -1));
        ans = min(ans, rec(0, k, n-2, nums, dp));

        dp.assign(n+2, vector<int>(k+1, -1));
        ans = min(ans, rec(1, k, n-1, nums, dp));

        dp.assign(n+2, vector<int>(k+1, -1));
        ans = min(ans, rec(1, k, n-2, nums, dp));

        return ans >= 1e9 ? -1 : ans;
    }
};