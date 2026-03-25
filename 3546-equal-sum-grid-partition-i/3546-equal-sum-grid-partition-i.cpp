class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long tot_sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tot_sum+=grid[i][j];
            }
        }
        //check row-wise division
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
            if(2*sum==tot_sum && i+1<n) return true;
        }
        //check col-wise division
        sum=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
            }
            if(2*sum==tot_sum && j+1<m) return true;
        }
        return false;
    }
};