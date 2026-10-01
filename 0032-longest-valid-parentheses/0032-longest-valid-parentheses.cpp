class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int,int>> st;
        int n = s.size();
        int mx = 0;

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            if(!st.empty()) {
                if(st.top().first == '(' && ch == ')') {
                    st.pop();

                    if(st.empty())
                        mx = max(mx, i + 1);
                    else
                        mx = max(mx, i - st.top().second);
                }
                else {
                    st.push({ch, i});
                }
            }
            else {
                st.push({ch, i});
            }
        }

        return mx;
    }
};