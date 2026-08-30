class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_idx=min_element(nums.begin(),nums.end())-nums.begin();
        int max_idx=max_element(nums.begin(),nums.end())-nums.begin();
        int r_del,l_del,full_left,full_right=0;
        int n=nums.size();
        if(min_idx>=max_idx){
            r_del=n-min_idx;
            l_del=max_idx+1;
            full_left=min_idx+1;
            full_right=n-max_idx;
        }else{
            r_del=n-max_idx;
            l_del=min_idx+1;
            full_right=n-min_idx;
            full_left=max_idx+1;
        }
        return min({r_del+l_del,full_right,full_left});
    }
};