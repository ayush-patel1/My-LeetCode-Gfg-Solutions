class Solution {
public:
#define ll long long

    ll gcd(ll a,ll b){
        while(b){
            ll t=b;
            b=a%b;
            a=t;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<ll>pre_max(n),pre_gcd(n);

        pre_max[0]=nums[0];
        pre_gcd[0]=gcd(nums[0],pre_max[0]);

        for(int i=1;i<n;i++){
            pre_max[i]=max(pre_max[i-1],1LL*nums[i]);
            pre_gcd[i]=gcd(nums[i],pre_max[i]);   // FIX
        }

        sort(pre_gcd.begin(),pre_gcd.end());

        ll sum=0;
        int l=0,r=n-1;

        while(l<r){
            sum+=gcd(pre_gcd[l],pre_gcd[r]);
            l++; r--;
        }

        return sum;
    }
};