class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1));
        
        for(int i = 0; i + k <= n; i++){
            for(int j = 0; j + k <= m; j++){
                vector<int> v; 
                
                for(int l = i; l < i + k; l++){
                    for(int x = j; x < j + k; x++){
                        v.push_back(grid[l][x]);
                    }
                }
                
                sort(v.begin(), v.end());
                
                int mn = 1e9;
                bool flg = false;
                
                for(int x = 0; x + 1 < v.size(); x++){
                    if(v[x] != v[x+1]){
                        mn = min(mn, v[x+1] - v[x]);
                        flg = true;
                    }
                }
                
                if(!flg) mn = 0;
                
                ans[i][j] = mn;
            }
        }
        
        return ans;
    }
};