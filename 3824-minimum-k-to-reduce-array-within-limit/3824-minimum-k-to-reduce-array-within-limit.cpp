class Solution {
public:
    bool check(long long k, vector<int>& nums) {
        if (k == 0) return false;
        long long ops = 0;
        for (int x : nums) {
            ops += (x + k - 1) / k;
            if (ops > k * k) return false;
        }
        return ops <= k * k;
    }

    int minimumK(vector<int>& nums) {
        long long l = 1, r = 1e9;
        long long ans = -1;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (check(mid, nums)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};