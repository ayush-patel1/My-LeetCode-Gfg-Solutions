

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1; 
        int prev_end = points[0][1]; 

        for (int i = 1; i < points.size(); ++i) {
            int x_start = points[i][0], x_end = points[i][1];
            
            if (x_start > prev_end) {
                arrows++;
                prev_end = x_end;
            }
        }

        return arrows;
    }
};

