class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int mx =nums[i], mn = nums[i];
            for (int j = 0; j <= i; j++) {
                mx=max(mx,nums[j]);
            }
            for (int j = i; j < n; j++) {
                mn=min(nums[j],mn);
            }
            cout<<mx<<" "<<mn<<endl;
            if(mx-mn<=k) return i;
        }
        return -1;
        
    }
};