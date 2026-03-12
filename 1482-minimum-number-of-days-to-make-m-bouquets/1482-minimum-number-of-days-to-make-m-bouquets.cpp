class Solution {
public:
    bool check(int l, vector<int>& arr, int k, int m) {
        int cnt = 0;
        int tot = 0;
        for (auto& it : arr) {
            if (it <= l) {
                cnt++;
                if (cnt == k) {
                    cnt = 0;
                    tot++;
                }
            }else cnt=0;
        }
        if (cnt >= k)
            tot++;
        return tot >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, bloomDay, k, m)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};