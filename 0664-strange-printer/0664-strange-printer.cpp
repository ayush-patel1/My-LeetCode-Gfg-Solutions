class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int solve(int i,int j,string &s){
        if(i==j) return 1;

        if(dp[i][j]!=0) return dp[i][j];

        int mn=1e9;

        for(int k=i;k<j;k++){
            int left=solve(i,k,s);
            int right=solve(k+1,j,s);
            mn=min(mn,left+right);
        }

        if(s[i]==s[j]) mn--;

        return dp[i][j]=mn;
    }

    int strangePrinter(string s) {
        n=s.size();
        dp.assign(n,vector<int>(n,0));
        return solve(0,n-1,s);
    }
};