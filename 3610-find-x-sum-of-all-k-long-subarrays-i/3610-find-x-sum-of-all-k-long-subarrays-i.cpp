class Solution {
public:
    int solve(vector<int>& nums, int x) {
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;
        
        vector<pair<int, int>> freq;
        for (auto& [num, count] : mp)
            freq.push_back({count, num});
        
        sort(freq.begin(), freq.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        });

        int sum = 0;
        for (int i = 0; i < min(x, (int)freq.size()); ++i)
            sum += freq[i].first * freq[i].second;
        
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        for (int i = 0; i <= nums.size() - k; ++i) {
            vector<int> window(nums.begin() + i, nums.begin() + i + k);
            ans.push_back(solve(window, x));
        }
        return ans;
    }
};