class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i], s = 0;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            a.push_back({s, nums[i]});
            mp[nums[i]] = i;
        }

        sort(a.begin(), a.end());

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = mp[a[i].second];
        }

        int ans = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (vis[i] || p[i] == i) continue;

            int cnt = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = p[j];
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};