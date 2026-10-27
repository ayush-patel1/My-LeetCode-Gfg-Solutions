class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();
        vector<vector<int>> d(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            set<char> st;

            for (int j = i; j < n; j++) {
                st.insert(s[j]);
                d[i][j] = st.size();
            }
        }

        long long ans = 0;

        for (int j = 0; j < n - 1; j++) {
            int cnt[27] = {};

            for (int k = j + 1; k < n; k++)
                cnt[d[j + 1][k]]++;

            for (int i = 0; i <= j; i++)
                ans += cnt[d[i][j]];
        }

        return ans;
    }
};