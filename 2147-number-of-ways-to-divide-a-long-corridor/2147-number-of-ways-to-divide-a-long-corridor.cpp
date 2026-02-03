class Solution {
public:
    const int mod = 1e9+7;

    int bs(string &s, int idx) {
        int n = s.size();
        int i = idx + 1;
        int plants = 0;
        while (i < n && s[i] != 'S') {
            plants++;
            i++;
        }
        return plants;
    }

    int numberOfWays(string corridor) {
        int cnt_s = count(corridor.begin(), corridor.end(), 'S');
        if (cnt_s == 0 || cnt_s & 1) return 0;

        int n = corridor.size();
        long long ans = 1;
        int curS = 0;

        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                curS++;
                if (curS % 2 == 0) {
                    if (curS == cnt_s) break;
                    int plants = bs(corridor, i);
                    ans = (ans * (plants + 1)) % mod;
                }
            }
        }
        return ans;
    }
};
