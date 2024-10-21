//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    void solve(vector<vector<int>> &mat, int x[], int y[], string dir, vector<string> &res, string temp, int row, int col, int n, int m) {
        if (row == n - 1 && col == m - 1) {
            res.push_back(temp);
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + y[i];
            int ncol = col + x[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1) {
                temp += dir[i];
                mat[row][col] = 0;  // Mark as visited
                solve(mat, x, y, dir, res, temp, nrow, ncol, n, m);
                mat[row][col] = 1;  // Unmark for backtracking
                temp.pop_back();
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<string> res;
        if (mat[0][0] == 0 || mat[n - 1][m - 1] == 0) 
            return res;
        string temp;
        string dir = "DULR";
        int x[] = {0, 0, -1, 1};
        int y[] = {1, -1, 0, 0};
        solve(mat, x, y, dir, res, temp, 0, 0, n, m);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends