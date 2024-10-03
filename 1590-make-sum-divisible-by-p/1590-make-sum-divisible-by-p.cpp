class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int to_remove = sum % p;
        
        if (to_remove == 0) return 0;  
        
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;  
        int min_len = n;
        long long prefix_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int target = (prefix_sum - to_remove + p) % p;  
            
            if (prefix_map.find(target) != prefix_map.end()) {
                min_len = min(min_len, i - prefix_map[target]);
            }
            
            prefix_map[prefix_sum] = i;
        }
        
        return (min_len == n) ? -1 : min_len;
    }
};
