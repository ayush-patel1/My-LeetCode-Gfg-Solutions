class Solution {
public:
    void solve(int curr, vector<vector<int>>& res, vector<int>& temp, int k, int n) {
        if (temp.size() == k) {
            if (n == 0) {
                res.push_back(temp);
                return;
            }
            return;
        }
        if (curr > 9 || n < 0) return;
        
        temp.push_back(curr);
        solve(curr + 1, res, temp, k, n - curr);
        temp.pop_back();
        
        solve(curr + 1, res, temp, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(1, res, temp, k, n);
        return res;
    }
};
