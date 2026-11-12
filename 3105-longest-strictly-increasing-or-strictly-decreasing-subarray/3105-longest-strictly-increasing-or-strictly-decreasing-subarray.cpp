class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int prev = nums[i], cnt = 1;
            int j = i + 1;
            while (j < n) {
                if (prev < nums[j]) {
                    prev = nums[j];
                    j++;
                    cnt++;
                } else
                    break;
            }
            mx = max(mx, cnt);
        }
        for (int i = n - 1; i >= 0; i--) {
            int prev = nums[i], cnt = 1;
            int j = i - 1;
            while (j >= 0) {
                if (prev < nums[j]) {
                    prev = nums[j];
                    j--;
                    cnt++;
                } else
                    break;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};