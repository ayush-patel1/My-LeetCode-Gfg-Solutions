class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 0;
        int n=nums.size();
        for(int i = 0; i < n; i++){
            int sum = 0;
            unordered_set<int>st;
            for(int j = i; j < n; j++){
                sum += nums[j];

                int rem = ((sum % k) + k) % k;

                if(rem == 0) ans = max(ans, j - i + 1);

                int x = (((nums[j] * 2) % k) + k) % k;
                st.insert(x);

                if(st.count(rem)) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};