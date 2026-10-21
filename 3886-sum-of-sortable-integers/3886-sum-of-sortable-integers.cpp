class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k) continue;

            bool flg = true;
            int pre = 0;

            for (int i = 0; i < n; i += k) {
                int desc = 0, mn = nums[i], mx = nums[i];

                for (int j = 0; j < k; j++) {
                    int a = nums[i + j];
                    int b = nums[i + (j + 1) % k];

                    if (a > b) desc++;
                    mn = min(mn, a);
                    mx = max(mx, a);
                }

                if (desc > 1 || pre > mn) {
                    flg = false;
                    break;
                }

                pre = mx;
            }

            if (flg) res += k;
        }

        return res;
    }
};