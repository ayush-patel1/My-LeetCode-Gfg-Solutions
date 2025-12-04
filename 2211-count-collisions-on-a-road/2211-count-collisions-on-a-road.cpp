class Solution {
public:
    int countCollisions(string s) {
        int n = s.size(), l = 0, r = n - 1;
        while (l < n && s[l] == 'L') l++;
        while (r >= 0 && s[r] == 'R') r--;
        int ans = 0;
        for (int i = l; i <= r; i++) if (s[i] != 'S') ans++;
        return ans;
    }
};
