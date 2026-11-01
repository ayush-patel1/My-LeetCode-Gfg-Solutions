class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        if(n == 1) return 0;
        if(n == 2) return nums.back() - nums[0];

        for(int i = 1; i < n; i++) {
            ans += nums[i] - nums[0];
        }

        return ans;
    }
};