class Solution {
public:
vector<int>dp;
int isPal(string &s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++; r--;
    }
    return true;
}
int solve(int idx,string &s){
    if(idx>=s.size()) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int res=1e9;
    for(int i=idx;i<s.size();i++){
        if(isPal(s,idx,i)){
           res=min(res,1+solve(i+1,s));
        }
    }
    return dp[idx]=res;
}
    int minCut(string s) {
        int n=s.size();
        dp.resize(n,-1);
        return solve(0,s)-1;
    }
};