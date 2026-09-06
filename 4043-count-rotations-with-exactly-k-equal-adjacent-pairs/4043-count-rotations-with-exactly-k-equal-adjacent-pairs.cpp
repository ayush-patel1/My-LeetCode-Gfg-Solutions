class Solution {
public:
    int countRotations(string s, int k) {
        s += s;
        int n = s.size() / 2;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int t = 0;

            for (int j = i; j < i + n - 1; j++) {
                if (s[j] == s[j + 1]) {
                    t++;
                }
            }

            if (t == k) cnt++;
        }

        return cnt;
    }
};