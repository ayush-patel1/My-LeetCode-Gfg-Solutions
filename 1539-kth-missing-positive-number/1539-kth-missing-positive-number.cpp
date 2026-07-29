class Solution {
public:
    int findKthPositive(vector<int>& vec, int k) {
        int n=vec.size();
        int l = 0, r = n - 1;
        int ans = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int missing = vec[mid] - (mid + 1);

            if (missing >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return k + ans;
    }
};