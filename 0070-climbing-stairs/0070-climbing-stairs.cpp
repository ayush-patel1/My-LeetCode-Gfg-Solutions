class Solution {
public:
vector<int>dp;
int solve(int idx,int n){
    if(idx==n) return 1;
    if(dp[idx]!=-1) return dp[idx];
    int ways=solve(idx+1,n);
    if(idx+2<=n) ways+=solve(idx+2,n);
    return dp[idx]=ways;
}
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return solve(0,n);
    }
};