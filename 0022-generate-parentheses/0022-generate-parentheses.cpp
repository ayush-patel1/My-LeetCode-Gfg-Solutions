class Solution {
public:
    void solve(vector<string>& res, int open, int close, string& temp) {
        if (open == 0 && close == 0) {
            res.push_back(temp);
            return;
        }

        if (open > 0) {
            temp.push_back('(');
            solve(res, open - 1, close, temp);
            temp.pop_back();
        }

        if (close > open) {
            temp.push_back(')');
            solve(res, open, close - 1, temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        solve(res, n, n, temp);
        return res;
    }
};