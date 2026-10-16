
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> f(n), s(n);
        int cur = INT_MIN;

        for (int i = 0; i < n; i++) {
            cur = max(values[i] + i, cur);
            f[i] = cur;
        }

        cur = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            s[i] = cur;
            cur = max(values[i] - i, cur);
        }

        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mx = max(mx, f[i] + s[i]);
        }

        return mx;
    }
};
