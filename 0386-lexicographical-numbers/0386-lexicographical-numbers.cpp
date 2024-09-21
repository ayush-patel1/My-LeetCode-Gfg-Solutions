class Solution {
public:
    void solve(int current, int n,vector<int>&res) {
    if (current > n) return; 

 
    res.push_back(current);

  
    for (int i = 0; i < 10; i++) {
        if (current * 10 + i > n) return;
        solve(current * 10 + i, n,res);
    }
}
    vector<int> lexicalOrder(int n) {
        vector<int>res;
       for(int i=1;i<=9;i++){
            solve(i,n,res);
       }
        return res;
    }
};