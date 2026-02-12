class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> f(26, 0);
            for (int j = i; j < n; j++) {
                f[s[j] - 'a']++;
                int c = 0; bool ok = true;
                for (int k = 0; k < 26; k++) {
                    if (f[k] > 0) {
                        if (c == 0) c = f[k];
                        else if (f[k] != c) { ok = false; break; }
                    }
                }
                if (ok) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
