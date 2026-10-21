class Solution {
public:
    bool check(int mid, string s, string p, vector<int>& r) {
        vector<bool> vis(s.length(), false);
        for (int i = 0; i < mid; i++) {
            vis[r[i]] = true;
        }

        int i = 0, j = 0;
        while (i < s.length() && j < p.length()) {
            if (!vis[i] && s[i] == p[j]) {
                j++;
            }
            i++;
        }

        return j == p.length();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size();
        int ans = l;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, s, p, removable)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};