class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char>st={'a','e','o','i','u'};
        while(!s.empty() && st.find(s.back())!=st.end()) s.pop_back();
        return s;
    }
};