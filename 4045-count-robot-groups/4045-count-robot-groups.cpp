class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = speed.size();
        int ans = 1;
        int mx = speed[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (position[i + 1] - position[i] > distance && mx >= speed[i]) {
                ans++;
                mx = speed[i];
            }
        }

        return ans;
    }
};