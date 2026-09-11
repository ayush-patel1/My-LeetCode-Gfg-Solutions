class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        map<int, int> mp;

        for (int d : digits)
            mp[d]++;

        int ans = 0;

        for (int l = 0; l <= 8; l += 2) {
            if (mp[l] == 0)
                continue;

            mp[l]--;

            for (int f = 1; f <= 9; f++) {
                if (mp[f] == 0)
                    continue;

                mp[f]--;

                for (int m = 0; m <= 9; m++) {
                    if (mp[m] > 0)
                        ans++;
                }

                mp[f]++;
            }

            mp[l]++;
        }

        return ans;
    }
};