class Solution {
public:
    int solve(int a, int b) {
        int d = abs(a - b);
        return min(d, 10 - d);
    }

    int minRotations(int n, string s) {
        int r = solve(0, s[0] - '0');

        for(int i = 1; i < n; i++) {
            r += solve(s[i - 1] - '0', s[i] - '0');
        }

        int ans = r;
        int last = s[n - 1] - '0';

        for(int i = 0; i < n; i++) {
            int cur = r;

            if(i == 0) {
                cur -= solve(0, s[0] - '0');
                cur += solve(0, last);
            }
            else {
                cur -= solve(s[i - 1] - '0', s[i] - '0');
                cur += solve(s[i - 1] - '0', last);
            }

            ans = min(ans, cur);
        }

        return ans;
    }
};