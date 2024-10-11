class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_row=m;
        int min_col=n;
        for(auto it:ops){
            int row=it[0];
            int col=it[1];
            min_row=min(min_row,row);
            min_col=min(min_col,col);
        }
        return min_row*min_col;
    }
};