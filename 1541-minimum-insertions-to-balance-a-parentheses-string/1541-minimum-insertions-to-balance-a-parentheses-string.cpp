class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int idx = 0, n = s.size();
        int cnt = 0;

        while (idx < n && s[idx] == ')') {
            cnt++;
            if (cnt == 2) {
                ans++;
                cnt = 0;
            }
            idx++;
        }

        if (cnt == 1) ans += 2;

        stack<char> st;

        for (int i = idx; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                    if (st.empty()) {
                        ans++;
                    } else {
                        st.pop();
                    }
                } else {
                    ans++;
                    if (st.empty()) {
                        ans++;
                    } else {
                        st.pop();
                    }
                }
            }
        }

        ans += 2 * st.size();

        return ans;
    }
};