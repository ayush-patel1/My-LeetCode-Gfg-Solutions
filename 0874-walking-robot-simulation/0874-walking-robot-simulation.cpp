class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>> st(obstacles.begin(), obstacles.end());
        int x = 0, y = 0;
        int d = 0;
        int ans = 0;
        for (auto& c : commands) {
            if (c == -2) {
                d = (d - 1 + 4) % 4;
            } else if (c == -1) {
                d = (d + 1) % 4;
            } else {
                if (d == 0) {
                    for (int i = 0; i < c; i++) {
                        if (st.find({x, y + 1}) != st.end()) break;
                        y++;
                        ans = max(ans, x*x + y*y);
                    }
                }
                if (d == 1) {
                    for (int i = 0; i < c; i++) {
                        if (st.find({x + 1, y}) != st.end()) break;
                        x++;
                        ans = max(ans, x*x + y*y);
                    }
                }
                if (d == 2) {
                    for (int i = 0; i < c; i++) {
                        if (st.find({x, y - 1}) != st.end()) break;
                        y--;
                        ans = max(ans, x*x + y*y);
                    }
                }
                if (d == 3) {
                    for (int i = 0; i < c; i++) {
                        if (st.find({x - 1, y}) != st.end()) break;
                        x--;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }
        return ans;
    }
};