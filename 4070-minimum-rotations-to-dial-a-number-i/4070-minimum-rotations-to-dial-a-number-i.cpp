class Solution {
public:
    int minRotations(string s) {
        int r = min(abs(s[0] - '0'), abs(10 - (s[0] - '0')));

        for(auto i = 1; i < s.size(); i++) {
            int n = s[i] - '0';
            int diff = abs(n - (s[i - 1] - '0'));

            r += min(diff, 10 - diff);
        }

        return r;
    }
};