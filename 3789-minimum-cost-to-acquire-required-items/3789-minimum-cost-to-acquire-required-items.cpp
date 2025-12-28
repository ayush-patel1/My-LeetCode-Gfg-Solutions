class Solution {
public:
#define ll long long
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll mn=1LL*cost1*need1+1LL*cost2*need2;
        ll min_item=min(need1,need2);
        mn=min(mn,min_item*costBoth+(need1-min_item)*cost1+(-min_item+need2)*cost2);
        mn=min(mn,1LL*max(need1,need2)*costBoth);
        return mn;
    }
};