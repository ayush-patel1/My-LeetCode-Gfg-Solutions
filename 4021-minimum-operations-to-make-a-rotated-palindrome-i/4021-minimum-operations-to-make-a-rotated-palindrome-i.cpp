class Solution {
public:
    int solve(string s, int l, int r) {
        int ops = 0;
        while (l <= r) {
            int d = abs(s[l] - s[r]);
            ops += min(d, 26 - d);
            l++;
            r--;
        }
        return ops;
    }

    int minOperations(string s) {
        int n = s.size();
        s += s;

        int mn = 1e9, r = 0;

        for (int i = 0; i < n; i++) {
            mn = min(mn, r + solve(s, i, i + n - 1));
            r++;
        }

        return mn;
    }
};