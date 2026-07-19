class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            while (l < r && s[l] != x) l++;
            while (l < r && s[r] != y) r--;

            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};