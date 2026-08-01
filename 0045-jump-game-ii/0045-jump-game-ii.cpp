class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1e9);
        dp[n-1]=0;  // we are already at target no need of any jump
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=nums[i];j++){  // try all possible number of step u can jump from i
                if(i+j<n){
                    dp[i]=min(dp[i],1+dp[i+j]);
                }
            }
        }
        return dp[0];
    }
};