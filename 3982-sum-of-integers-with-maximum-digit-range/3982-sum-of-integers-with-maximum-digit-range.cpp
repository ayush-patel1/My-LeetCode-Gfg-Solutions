class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int mxRange = 0;

        for (int num : nums) {
            string s = to_string(num);
            int mx = 0, mn = 9;
            for (char c : s) {
                mx = max(mx, c - '0');
                mn = min(mn, c - '0');
            }
            mxRange = max(mxRange, mx - mn);
        }

        int sum = 0;
        for (int num : nums) {
            string s = to_string(num);
            int mx = 0, mn = 9;
            for (char c : s) {
                mx = max(mx, c - '0');
                mn = min(mn, c - '0');
            }
            if (mx - mn == mxRange)
                sum += num;
        }

        return sum;
    }
};