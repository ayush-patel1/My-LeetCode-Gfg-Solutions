class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        //caluclate the suffix and prefix
        //suffix[i]=max_lenght of continius non-decreasing elements till i
        //prefix[i]=max_length of continuous non-increasing elements till j
        vector<int>pre(n,1),suf(n,1);
        for(int i=1;i<n;i++){
            if(nums[i-1]>=nums[i]){
                pre[i]=pre[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>=nums[i]){
                suf[i]=suf[i+1]+1;
            }
        }
        vector<int>ans;
        for(int i=1;i<n-1;i++){
            int l=pre[i-1];
            int r=suf[i+1];
            if(l>=k && r>=k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};