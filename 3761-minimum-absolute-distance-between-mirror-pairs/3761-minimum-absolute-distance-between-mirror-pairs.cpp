class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<string, int> mp;
        int minGap = INT_MAX;

        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            if (mp.find(s) != mp.end()) {
                minGap = min(minGap, i - mp[s]);
                if (minGap == 1)
                    return 1;
            }
            while (s.back() == '0' && s.size() > 1)
                s.pop_back();
            reverse(s.begin(), s.end());

            mp[s] = i;
        }

        return (minGap == INT_MAX) ? -1 : minGap;
    }
};
