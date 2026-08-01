class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int prev_end = intervals[0][1];
        int removals = 0;

        for (int i = 1; i < n; i++) {
            auto& it = intervals[i];
            if (it[0] < prev_end) {
                prev_end=min(prev_end,it[1]);
                removals++;
            } else {
                prev_end = it[1];
            }
        }

        return removals;
    }
};