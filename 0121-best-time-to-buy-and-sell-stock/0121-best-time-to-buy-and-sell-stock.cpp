class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_profit=INT_MIN;
        int min_cost=*max_element(prices.begin(),prices.end());
        for(int i=0;i<n;i++){
            int curr_profit=prices[i]-min_cost;
            max_profit=max(max_profit,curr_profit);
            min_cost=min(min_cost,prices[i]);
        }
        return max_profit;
    }
};