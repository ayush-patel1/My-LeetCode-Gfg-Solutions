
#define ll long long

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll a = need1, b = need2;
        ll c1 = cost1, c2 = cost2, cb = costBoth;

        ll mn = min(a, b);

        ll ans = mn * min(cb, c1 + c2);

        ans += (a - mn) * min(cb, c1);
        ans += (b - mn) * min(cb, c2);

        return ans;
    }
};
