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
            }

            string t = s;
            reverse(t.begin(), t.end());

            while (t.size() > 1 && t[0] == '0')
                t.erase(t.begin());

            mp[t] = i;
        }

        return (minGap == INT_MAX) ? -1 : minGap;
    }
};