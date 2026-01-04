class Solution {
public:
    #define ll long long

    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.size();
        ll a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && t[i] == '1') a++;
            else if (s[i] == '1' && t[i] == '0') b++;
        }

        ll cost = 0;

        ll p = min(a, b);
        cost += p * min(1LL * swapCost, 2LL * flipCost);

        a -= p;
        b -= p;

        ll r = llabs(a - b);
        ll pairs = r / 2;

        cost += pairs * min(1LL * crossCost + swapCost, 2LL * flipCost);

        if (r % 2 == 1) cost += flipCost;

        return cost;
    }
};
