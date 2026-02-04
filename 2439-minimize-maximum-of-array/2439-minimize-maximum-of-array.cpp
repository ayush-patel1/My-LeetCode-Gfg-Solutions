class Solution {
public:
#define ll long long

    bool check(vector<int>& nums, ll k){
        ll gain = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] <= k){
                gain += (k - nums[i]);
            } else {
                ll need = nums[i] - k;
                if(gain < need) return false;
                gain -= need;
            }
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        ll l = 0, r = 1e9;
        ll ans = -1;
        while(l <= r){
            ll mid = l + (r - l) / 2;
            if(check(nums, mid)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};


    //start kro piche se traverse krna aur adjacnet ke bich mai equally ditribute krne ka kosis kro // incase sum of nums[i] & nums[i-1] is odd then add extra to nums[i-1] // as it can distrubute it further to its previous elems but nums[i] does not have any such chance to do so
        //we can use binary search as here there is monotonocity