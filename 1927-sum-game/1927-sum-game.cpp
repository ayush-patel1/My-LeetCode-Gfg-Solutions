class Solution {
public:
    bool sumGame(string s) {
        int n = s.size(), h = n / 2;
        int a = 0, b = 0, q1 = 0, q2 = 0;

        for (int i = 0; i < h; i++) {
            if (s[i] == '?') q1++;
            else a += s[i] - '0';
        }

        for (int i = h; i < n; i++) {
            if (s[i] == '?') q2++;
            else b += s[i] - '0';
        }

        int q = q1 - q2;
        int d = a - b;

        if (q % 2 != 0) return true;

        if (d * 2 == -9 * q) return false;

        return true;
    }
};