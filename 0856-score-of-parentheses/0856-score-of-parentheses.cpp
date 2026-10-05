class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int ans = 0, cur = 0;
        vector<int> v;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') cur++;

            if(s[i] == ')' && s[i-1] == '(') {
                v.push_back(cur);
            }

            if(s[i] == ')') cur--;
        }

        for(auto &it : v) {
            ans += (1 << (it - 1));
        }

        return ans;
    }
};