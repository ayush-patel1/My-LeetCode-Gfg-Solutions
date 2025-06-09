class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:arr) pq.push(it);
        int res=0;
        while(pq.size()>1){
           int a=pq.top();
           pq.pop();
           int b=pq.top();
           pq.pop();
           res+=(a+b);
           pq.push(a+b);
        }
        return res;
    }
};