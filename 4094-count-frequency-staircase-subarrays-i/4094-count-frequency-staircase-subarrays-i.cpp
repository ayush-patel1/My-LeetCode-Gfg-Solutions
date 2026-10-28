class Solution {
public:
    bool check(unordered_map<int, int>& mp, vector<int>& v) {
        int cnt = 1;
        for (auto &it : v) {
            if (mp[it] != cnt) return false;
            cnt++;
        }
        return true;
    }

    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            vector<int> v;

            for (int j = i; j < n; j++) {
                mp[nums[j]]++;

                if (mp[nums[j]] == 1) {
                    v.push_back(nums[j]);
                }

                if (check(mp, v)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};