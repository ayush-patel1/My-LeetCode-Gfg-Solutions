class Solution {
public:
    int bs(int n, vector<int>& nums, int i){
        int m = nums.size();
        int left = i, right = m - 1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= n){
                ans = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int mx = 0;

        for(int i = 0; i < n; i++){
            int cur = bs(nums1[i], nums2, i) - i ;
            mx = max(mx, cur);  
        }
        return mx;
    }
};