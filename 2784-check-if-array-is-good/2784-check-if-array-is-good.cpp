class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        for (auto &it : nums) mp[it]++;

        int o = 0, t = 0, elem = -1;

        vector<int> v;

        for (auto &it : mp) {
            if (it.second == 1) {
                o++;
                v.push_back(it.first);
            }

            if (it.second == 2) {
                elem = it.first;
                t++;
            }
        }

        if (o != n - 2) return false;

        sort(v.begin(), v.end());

        int r = 1;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] != r) return false;
            r++;
        }

        if (t != 1 || elem != n - 1) return false;

        return true;
    }
};