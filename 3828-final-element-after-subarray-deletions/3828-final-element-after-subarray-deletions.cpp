class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n=nums.size();
        int max_elem=*max_element(nums.begin(),nums.end());
        //es case mai Alice shurwat mai hi left ya right se pura element le lega except corner one
        return max(nums[0],nums.back()); 
    }
};

