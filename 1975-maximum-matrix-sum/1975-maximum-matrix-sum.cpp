class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0, neg = 0, mini = 1e9;

        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] < 0) neg++;
                if(mini > abs(matrix[i][j]))    mini = abs(matrix[i][j]);
                sum += abs(matrix[i][j]);
            }
        }

        if(neg%2 != 0) sum -= 2*mini;
        return sum;  
    }
};