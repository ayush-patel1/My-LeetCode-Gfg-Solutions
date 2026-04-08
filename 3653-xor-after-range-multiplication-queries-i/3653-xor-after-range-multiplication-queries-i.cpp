class Solution {
public:
const int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        for(auto query:queries){
            int idx=query[0],r=query[1],
            k=query[2],v=query[3];
            while(idx<=r){
                nums[idx]=(1LL*nums[idx] * v) % mod;
                idx += k;
            }
        }
        int ans=0;
        for(auto it:nums) ans=ans^it;
        return ans;
    }
};