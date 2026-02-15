class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp, f;

        for (auto &it : nums) 
            mp[it]++;

        for (auto &it : mp) 
            f[it.second]++;

        for (auto &it : nums) {
            if (f[mp[it]] == 1) 
                return it;
        }

        return -1;
    }
};
