class Solution {
public:
    #define ll long long
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return -1;

        vector<int> navorelitu = nums;

        vector<ll> pre_sum(n), suf_pro(n);

        pre_sum[0] = nums[0];
        suf_pro[n-1] = nums[n-1];

        for(int i=1;i<n;i++)
            pre_sum[i] = pre_sum[i-1] + nums[i];

        ll LIM = 1e14;

        for(int i=n-2;i>=0;i--){
            if(suf_pro[i+1] > LIM / nums[i])
                suf_pro[i] = LIM + 1;
            else
                suf_pro[i] = suf_pro[i+1] * nums[i];
        }

        for(int i=0;i<n;i++){
            if(i==0){
                if(suf_pro[i+1] == 0) return 0;
            }
            else if(i==n-1){
                if(pre_sum[i-1] == 1) return n-1;
            }
            else{
                if(pre_sum[i-1] == suf_pro[i+1]) return i;
            }
        }

        return -1;
    }
};