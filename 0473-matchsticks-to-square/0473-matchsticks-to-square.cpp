class Solution {
public:
    vector<int> vis;
    int side;

    bool solve(int idx, vector<int>& arr, int segs, int target) {
        if (segs == 1) return true;
        if (target == 0) return solve(0, arr, segs - 1, side);
        for (int i = idx; i < arr.size(); i++) {
            if (!vis[i] && target - arr[i] >= 0) {
                vis[i] = true;
                if (solve(i + 1, arr, segs, target - arr[i])) return true;
                vis[i] = false;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int t = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (t % 4 != 0) return false;
        side = t / 4;
        vis.assign(n, 0);
        return solve(0, matchsticks, 4, side);
    }
};