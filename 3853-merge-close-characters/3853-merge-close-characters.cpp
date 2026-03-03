class Solution {
public:
    string mergeCharacters(string s, int k) {
        while (true) {
            int n = s.size();
            int min_idx = -1;
            int min_dis = 1e9;

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n && j - i <= k; j++) {
                    if (s[i] == s[j]) {
                        if (i < min_dis || (i == min_dis && j < min_idx)) {
                            min_dis = i;
                            min_idx = j;
                        }
                    }
                }
            }

            if (min_idx == -1) break;

            string t = "";
            for (int i = 0; i < n; i++) {
                if (i != min_idx) t += s[i];
            }

            s = t;
        }

        return s;
    }
};