class Solution {
public:
    bool check(map<int,int>& mp, int x) {

        for (int a = 1; a < x; a++) {
            int b = x - a;

            if (!mp.count(a) || !mp.count(b))
                continue;

            if (a == b) {
                if (mp[a] >= 2)
                    return true;
            }
            else
                return true;
        }

        for (int b = x + 1; b <= 500; b++) {
            int a = b - x;

            if (!mp.count(a) || !mp.count(b))
                continue;

            if (a == x) {
                if (mp[a] >= 2)
                    return true;
            }
            else
                return true;
        }

        return false;
    }

    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, ans = 1;
        map<int,int> mp;

        for (int r = 0; r < n; r++) {
            mp[nums[r]]++;

            while (check(mp, nums[r])) {
                mp[nums[l]]--;

                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};