class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> pos(n+1);
        for(int i = 0; i < n; i++){
            pos[nums[i]].push_back(i);
        }
        
        int ans = 1e9;
        for(int x = 1; x <= n; x++){
            auto &v = pos[x];
            
            for(int i = 0; i + 2 < v.size(); i++){
                ans = min(ans, 2 * (v[i+2] - v[i]));
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};