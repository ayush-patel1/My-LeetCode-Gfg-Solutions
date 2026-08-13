class Solution {
public:
    bool check(vector<int>& piles, int mid, int h) {
        int t = 0;
        for (auto &p : piles) {
            t += (p + mid - 1) / mid;
            if (t > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (check(piles, mid, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};