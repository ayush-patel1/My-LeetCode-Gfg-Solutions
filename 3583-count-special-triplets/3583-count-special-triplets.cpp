class Solution {
public:
const int mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>pr,af;
        for(auto &x:nums) af[x]++;
        int cnt=0;
        for(auto &x:nums){
            af[x]--;
            if(af[x]==0) af.erase(x);
            if(pr.count(x*2) && af.count(x*2)){
                cnt=(cnt+1LL*pr[x*2]*af[x*2])%mod;
                // cout<<cnt<<endl;

            }
            pr[x]++;
        }
        return cnt;
    }
};