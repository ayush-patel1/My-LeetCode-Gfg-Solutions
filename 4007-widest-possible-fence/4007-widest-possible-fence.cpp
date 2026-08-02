class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> freq;

        for (int x : planks)
            freq[x]++;

        vector<pair<int, int>> vals(freq.begin(), freq.end());

        int m = vals.size();

        for (int i = 0; i < m; i++) {
            freq[2 * vals[i].first] += vals[i].second / 2;

            for (int j = i + 1; j < m; j++) {
                freq[vals[i].first + vals[j].first] +=
                    min(vals[i].second, vals[j].second);
            }
        }

        int ans = 0;
        for (auto it : freq)
            ans = max(ans, it.second);

        return ans;
    }
};