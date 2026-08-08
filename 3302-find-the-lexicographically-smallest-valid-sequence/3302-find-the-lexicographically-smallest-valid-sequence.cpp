class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> res, right(n);

        int r = m - 1, c = 0;

        for (int i = n - 1; i >= 0; i--) {
            right[i] = c;
            if (r >= 0 && word1[i] == word2[r]) {
                r--;
                c++;
            }
        }

        int i = 0, j = 0, used = 1;

        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                i++;
                j++;
            } else if (used && right[i] >= m - 1 - j) {
                res.push_back(i);
                used--;
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == m ? res : vector<int>{};
    }
};