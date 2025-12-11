class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& a) {
        vector<int>xmin(n + 1, 1e6);
        vector<int>xmax(n + 1, 0);
        vector<int>ymin(n + 1, 1e6);
        vector<int>ymax(n + 1, 0);
        for (auto e : a) {
            int x = e[0], y = e[1];
            ymin[x] = min(ymin[x], y);
            ymax[x] = max(ymax[x], y);
            xmin[y] = min(xmin[y], x);
            xmax[y] = max(xmax[y], x);
        }
        int c = 0;
        for (auto e : a) {
            int x = e[0], y = e[1];
            if (ymax[x] > y && ymin[x] < y && xmax[y] > x && xmin[y] < x) {
                c++;
            }
        }
        return c;
    }
};