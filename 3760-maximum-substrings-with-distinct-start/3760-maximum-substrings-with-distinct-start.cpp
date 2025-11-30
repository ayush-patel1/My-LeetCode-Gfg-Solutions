class Solution {
public:
    int maxDistinct(string s) {
        int n=s.size();
        unordered_set<char>st(s.begin(),s.end());
        return st.size();
    }
};