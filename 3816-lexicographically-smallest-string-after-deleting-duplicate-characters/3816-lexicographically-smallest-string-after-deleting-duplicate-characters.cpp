class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int> freq(26, 0), used(26, 0);
        for(char c : s) freq[c - 'a']++;

        stack<char> st;

        for(char c : s) {
            int x = c - 'a';
            freq[x]--;

            while(!st.empty()) {
                char t = st.top();
                int y = t - 'a';
                if(t > c && used[y] + freq[y] > 1) {
                    st.pop();
                    used[y]--;
                } else break;
            }

            st.push(c);
            used[x]++;
        }

        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        while(ans.size() > 1) {
            char last = ans.back();
            bool found = false;
            for(int i = 0; i < (int)ans.size() - 1; i++) {
                if(ans[i] == last) {
                    found = true;
                    break;
                }
            }
            if(found) ans.pop_back();
            else break;
        }

        return ans;
    }
};
