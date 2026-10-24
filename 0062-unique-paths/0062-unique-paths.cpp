class Solution {
public:
    int uniquePaths(int m, int n) {
     
        vector<vector<int>>dp(m,vector<int>(n,1));
           dp[0][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int up=dp[i-1][j];
                int down=dp[i][j-1];
                dp[i][j]=up+down;
            }
        }
        return dp[m-1][n-1];
    }
};