class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        //brute force
        // while(k--){
        //     int t=nums.back();
        //     //then shift all elements then intitlaise first to what stored i t;
        // }
        //optimal
         int l = n - k;
        reverse(nums.begin(), nums.begin() + l);
        reverse(nums.begin() + l, nums.end());
        reverse(nums.begin(), nums.end());
    }
};