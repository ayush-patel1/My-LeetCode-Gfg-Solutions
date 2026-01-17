class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n = towers.size();
        int max_q = -1;
        int max_idx = -1;

        for (int i = 0; i < n; i++) {
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];

            int r = abs(x - center[0]) + abs(y - center[1]);

            if (r <= radius) {
                if (q > max_q ||
                    (q == max_q &&
                     (max_idx == -1 ||
                      x < towers[max_idx][0] ||
                      (x == towers[max_idx][0] && y < towers[max_idx][1])))) {

                    max_q = q;
                    max_idx = i;
                }
            }
        }

        if (max_idx == -1) return {-1, -1};
        return {towers[max_idx][0], towers[max_idx][1]};
    }
};