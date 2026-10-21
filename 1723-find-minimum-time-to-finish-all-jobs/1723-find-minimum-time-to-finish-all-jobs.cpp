class Solution {
public:
    bool check(int i, vector<int>& jobs, vector<int>& vis, int k, int mid) {
        if (i == jobs.size()) return true;

        for (int j = 0; j < k; j++) {
            if (vis[j] + jobs[i] <= mid) {
                vis[j] += jobs[i];

                if (check(i + 1, jobs, vis, k, mid)) return true;

                vis[j] -= jobs[i];
            }

            if (vis[j] == 0) break;
        }

        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        int l = *max_element(jobs.begin(), jobs.end());
        int r = accumulate(jobs.begin(), jobs.end(), 0);
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<int> vis(k, 0);

            if (check(0, jobs, vis, k, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};