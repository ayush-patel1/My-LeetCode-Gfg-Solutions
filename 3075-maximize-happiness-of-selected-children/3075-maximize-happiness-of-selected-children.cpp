class Solution {
public:
#define  ll long long
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end());
        ll ans=0, d=0;
        for(int i=n-1;i>=0 && k--;i--){
            if(happiness[i]-d>0) ans+=happiness[i]-d;
            d++;
        }
        return ans;
    }
};