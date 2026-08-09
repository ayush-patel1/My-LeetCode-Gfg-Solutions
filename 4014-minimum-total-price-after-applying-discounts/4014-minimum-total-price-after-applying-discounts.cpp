class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();

        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double sum = 0;

        for (int i = 0; i < min(n, m); i++) {
            sum += prices[i] * (100.0 - discounts[i]) / 100.0;
        }

        for (int i = m; i < n; i++) {
            sum += prices[i];
        }

        return sum;
    }
};