class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(matrix[j][i]==1){
                    cnt++;
                }
                else{
                    cnt=0;
                }
                v[j][i]=cnt;
            }
        }

        int max_ans=0;
        for(int i=0;i<n;i++){
            auto &a=v[i];
            sort(a.begin(),a.end());
            for(int j=0;j<m;j++){
                max_ans=max(max_ans,a[j]*(m-j));
            }
        }
        return max_ans;
    }
};
//consective ones ko prefix sum lete jaau column wise
//then sort row wise in non-decreasing order 
//then update global max with mat[i][j]*(n-j+1)
//this is bcz kyuki uske aage wala contribute to krega hi bcz usme itna to height h hi
//jitna chote wale ke pas h, bcz uske right wala pkka bda h bcz sorted