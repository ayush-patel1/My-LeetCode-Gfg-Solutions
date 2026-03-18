class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
         int n=grid.size();
         int m=grid[0].size();
         vector<vector<int>>pre(n+1,vector<int>(m+1,0));
         int cnt=0;
         if(grid[0][0]>k){
            return 0;
         }
        //  cout<<pre[0][1]<<endl;
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]=pre[i-1][j]+pre[i][j-1]+grid[i-1][j-1]-pre[i-1][j-1];
                if(pre[i][j]<=k){
                    cnt++;
                }
            }

         }
        //  cout<<cnt<<endl;
         return cnt;
    }
};