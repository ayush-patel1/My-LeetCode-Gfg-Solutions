class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n=prices.size(); 
        int m=discounts.size();
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        double sum=0;
        for(int i=0;i<min(n,m);i++){
           sum+=((100.0-discounts[i]*1.0)*prices[i]*1.0)/100.0;
        }
        if(n>min(n,m)){
            for(int i=m;i<n;i++){
               sum+=prices[i];
            }
        }
        return sum;
    }
};