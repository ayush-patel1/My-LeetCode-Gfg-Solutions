class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, unordered_set<int>> mp;
        for (auto &r : reservedSeats)
            mp[r[0]].insert(r[1]);

        int ans = 2 * n;

        for (auto &it : mp) {
            bool flg = true;

            // Check 2-9
            for (int i = 2; i <= 9; i++) {
                if (it.second.count(i)) {
                    flg = false;
                    break;
                }
            }

            if (flg) continue; // 2 families

            // Check 2-5
            flg = true;
            for (int i = 2; i <= 5; i++) {
                if (it.second.count(i)) {
                    flg = false;
                    break;
                }
            }

            if (flg) {
                ans--;
                continue;
            }

            // Check 6-9
            flg = true;
            for (int i = 6; i <= 9; i++) {
                if (it.second.count(i)) {
                    flg = false;
                    break;
                }
            }

            if (flg) ans--;
            else {
                // Check 4-7
                flg = true;
                for (int i = 4; i <= 7; i++) {
                    if (it.second.count(i)) {
                        flg = false;
                        break;
                    }
                }
                if (flg) ans--;
                else ans -= 2;
            }
        }

        return ans;
    }
};