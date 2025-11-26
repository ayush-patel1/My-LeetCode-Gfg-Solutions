class Solution {
public:
int n, m;
const int MOD = 1e9+7;
vector<vector<vector<long long>>> dp;

int solve(vector<vector<int>>& grid, int k, int r, int c, int sum){

    if(r>=n || c>=m || r<0 || c<0) return 0;

    sum = (sum + grid[r][c]) % k;

    if(r == n-1 && c == m-1){
        return sum == 0;
    }

    if(dp[r][c][sum] != -1) return dp[r][c][sum];

    long long right = solve(grid, k, r, c+1, sum);
    long long down  = solve(grid, k, r+1, c, sum);

    return dp[r][c][sum] = (right + down) % MOD;
}

int numberOfPaths(vector<vector<int>>& grid, int k) {
    n = grid.size();
    m = grid[0].size();
    dp.resize(n, vector<vector<long long>>(m, vector<long long>(k, -1)));
    return solve(grid, k, 0, 0, 0);
}
};
