class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> pre(n+1, vector<int>(m+1,0));
        vector<vector<int>> preX(n+1, vector<int>(m+1,0));

        int cnt=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int val=0;
                if(grid[i-1][j-1]=='X') val=1;
                else if(grid[i-1][j-1]=='Y') val=-1;

                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + val;

                preX[i][j] = preX[i-1][j] + preX[i][j-1] - preX[i-1][j-1];
                if(grid[i-1][j-1]=='X') preX[i][j]++;

                if(pre[i][j]==0 && preX[i][j]>0) cnt++;
            }
        }

        return cnt;
    }
};