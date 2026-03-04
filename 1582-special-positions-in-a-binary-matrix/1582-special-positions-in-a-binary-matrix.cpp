class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt=0;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            int cur=0; int col=-1;
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    cur++;
                    col=j;
                }
            }
            if(cur==1){
                cur=0;
                for(int i=0;i<n;i++){
                    if(mat[i][col]){
                        cur++;
                    }
                }
                if(cur==1) cnt++; 
            }
        }
        return cnt;
    }
};