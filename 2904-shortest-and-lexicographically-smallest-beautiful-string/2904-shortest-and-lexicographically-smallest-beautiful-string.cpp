class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int mn = INT_MAX;
        unordered_map<char, int> mp;
        string ans = "";

        while (r < n) {
            mp[s[r]]++;

            while (l <= r && mp['1'] > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }

            if (mp['1'] == k) {
                while (s[l] == '0') {
                    mp[s[l]]--;
                    if (mp[s[l]] == 0)
                        mp.erase(s[l]);
                    l++;
                }

                string cur = s.substr(l, r - l + 1);

                if (cur.size() < mn || 
                    (cur.size() == mn && cur < ans)) {
                    mn = cur.size();
                    ans = cur;
                }
            }

            r++;
        }

        return ans;
    }
};