class Solution {
public:
void rotate(vector<int>& nums, int k){
    int n = nums.size();
    if(n == 0) return;
    k %= n;
    if(k == 0) return;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
}

    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> v;
        for(auto &num : nums){
            if(num >= 0) v.push_back(num);
        }

        if(v.size() == 0) return nums;

        rotate(v, k);

        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                nums[i] = v[j++];
            }
        }
        return nums;
    }
};
