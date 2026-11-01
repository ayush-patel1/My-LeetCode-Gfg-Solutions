class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        int mn=1e9;
        for(int i=0;i+1<n;i+=2){
            string s=to_string(nums[i])+to_string(nums[i+1]);
            mn=min(mn,stoi(s));
        }
        return mn;
    }
};