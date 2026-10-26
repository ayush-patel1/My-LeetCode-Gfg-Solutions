class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size(), ans = 0;
        vector<vector<int>> d(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            set<char> st;
            for (int j = i; j < n; j++) {
                st.insert(s[j]);
                d[i][j] = st.size();
            }
        }

        vector<vector<int>> freq(n, vector<int>(27, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                freq[i][d[i][j]]++;
            }
        }

        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i <= j; i++) {
                ans += freq[j + 1][d[i][j]];
            }
        }

        return ans;
    }
};