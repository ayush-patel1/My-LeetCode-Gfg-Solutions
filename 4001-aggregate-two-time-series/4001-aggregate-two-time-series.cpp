class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        unordered_set<int> st;
        for (auto &it : series1) st.insert(it[0]);
        for (auto &it : series2) st.insert(it[0]);

        vector<vector<int>> ans;

        for (int x : st) {
            int sum = 0;

            auto it1 = lower_bound(series1.begin(), series1.end(), vector<int>{x, 0});
            if (it1 != series1.end())
                sum += (*it1)[1];

            auto it2 = lower_bound(series2.begin(), series2.end(), vector<int>{x, 0});
            if (it2 != series2.end())
                sum += (*it2)[1];

            ans.push_back({x, sum});
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};