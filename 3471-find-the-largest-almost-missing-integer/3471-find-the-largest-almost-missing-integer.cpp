class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        if (k == 1) {
            int ans = -1;
            for (auto it : mp) {
                if (it.second == 1)
                    ans = max(ans, it.first);
            }
            return ans;
        }

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        int ans = -1, flg = 0;

        if (mp[nums[0]] == 1) {
            ans = nums[0];
            flg = 1;
        }

        if (mp[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
            flg = 1;
        }

        if (!flg)
            return -1;

        return ans;
    }
};