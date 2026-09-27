class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, mx = 0;
        
        map<pair<int,int>, int> mp;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                ans++;
            } else {
                int x = min(nums[i], nums[i - 1]);
                int y = max(nums[i], nums[i - 1]);
                mx = max(mx, ++mp[{x, y}]);
            }
        }
        
        return ans + mx;
    }
};