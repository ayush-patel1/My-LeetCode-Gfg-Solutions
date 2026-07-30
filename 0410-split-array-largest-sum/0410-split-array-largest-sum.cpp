class Solution {
public:
    bool solve(int mid, vector<int>& nums, int k) {
        int cur = 0;
        int cnt = 1;

        for (int x : nums) {
            if (cur + x <= mid) {
                cur += x;
            } else {
                cnt++;
                cur = x;
                if (cnt > k) return false;
            }
        }

        return true;   // or return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (solve(mid, nums, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};