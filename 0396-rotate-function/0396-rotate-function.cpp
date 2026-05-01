class Solution {
public:
    #define ll long long

    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        ll sum = 0;
        ll curr = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            curr += 1LL * i * nums[i];
        }
        
        ll ans = curr;
        
        for (int k = 1; k < n; k++) {
            curr = curr + sum - 1LL * n * nums[n - k];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};