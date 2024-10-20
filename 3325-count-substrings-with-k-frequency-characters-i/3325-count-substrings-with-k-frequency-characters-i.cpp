class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int count_freq = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if (freq[s[j] - 'a'] >= k) {
                    count_freq += n - j;
                    break;
                }
            }
        }
        return count_freq;
    }
};
