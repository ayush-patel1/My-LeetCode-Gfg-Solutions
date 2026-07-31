class Solution {
public:
    unordered_set<string> st;
    vector<int>dp;
    bool solve(int idx, string temp, vector<string>& w, string &s) {
        if (idx >= s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        for (int i = idx; i < s.size(); i++) {
            temp += s[i];

            if (st.find(temp) != st.end()) {
                if (solve(i + 1, "", w, s))
                    return true;
            }
        }
        return dp[idx]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto &w : wordDict) st.insert(w);
        dp.resize(s.size(),-1);
        return solve(0, "", wordDict, s);
    }
};