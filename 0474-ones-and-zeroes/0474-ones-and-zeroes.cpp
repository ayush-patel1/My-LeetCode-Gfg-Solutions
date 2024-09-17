class Solution {
public:
    vector<vector<vector<int>>> memo;

    int helper(vector<pair<int, int>>& counts, int index, int zerosLeft, int onesLeft) {
        if (index == counts.size()) {
            return 0;
        }

        if (memo[index][zerosLeft][onesLeft] != -1) {
            return memo[index][zerosLeft][onesLeft];
        }

        int skip = helper(counts, index + 1, zerosLeft, onesLeft);

        int take = 0;
        int zeros = counts[index].first;
        int ones = counts[index].second;

        if (zerosLeft >= zeros && onesLeft >= ones) {
            take = 1 + helper(counts, index + 1, zerosLeft - zeros, onesLeft - ones);
        }

        return memo[index][zerosLeft][onesLeft] = max(skip, take);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> counts;
        
        for (const string& s : strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;
            counts.push_back({zeros, ones});
        }
        
        memo = vector<vector<vector<int>>>(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return helper(counts, 0, m, n);
    }
};
