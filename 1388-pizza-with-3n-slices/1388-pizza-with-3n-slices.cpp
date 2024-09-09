#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(const vector<int>& slices, int start, int end, int k) {
        int n = end - start + 1;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                int take = (i >= 2) ? dp[i - 2][j - 1] + slices[start + i - 1] : slices[start + i - 1];
                int notTake = dp[i - 1][j];
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n][k];
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;

        // Case 1: Exclude the first slice
        int case1 = solve(slices, 1, n - 1, k);

        // Case 2: Exclude the last slice
        int case2 = solve(slices, 0, n - 2, k);

        return max(case1, case2);
    }
};


