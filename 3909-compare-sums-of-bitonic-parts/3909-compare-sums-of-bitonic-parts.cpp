class Solution {
public:
#define ll long long
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        ll i_sum=nums[0];
        if(nums[0]>nums[1]) return 1;
        int idx=-1;
        for(int i=1;i<n;i++){
           if(nums[i-1]<nums[i]){
             i_sum+=nums[i];
           }else{
            idx=i;
            break;
           }
        }
        ll d_sum=nums[idx-1];
        for(int i=idx;i<n;i++){
            d_sum+=nums[i];
        }
        // cout<<i_sum<<" "<<d_sum<<endl;
        if(i_sum>d_sum) return 0;
        else if(d_sum>i_sum) return 1;
        return -1;
    }

};