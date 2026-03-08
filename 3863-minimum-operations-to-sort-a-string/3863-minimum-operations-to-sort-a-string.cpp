class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string t = s;
        sort(t.begin(), t.end());

        int l = 0;
        while (l < n && s[l] == t[l]) l++;

        if (l == n) return 0;

        int r = n - 1;
        while (r >= 0 && s[r] == t[r]) r--;

        if (l > 0 || r < n - 1) return 1;

        if (n == 2) return -1;

        char mn = t[0], mx = t[n - 1];

        for (int i = 0; i < n - 1; i++)
            if (s[i] == mn) return 2;

        for (int i = 1; i < n; i++)
            if (s[i] == mx) return 2;

        return 3;
    }
};