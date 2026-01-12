class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int tot=0;
        int n=points.size();
        for(int i=0;i+1<n;i++){
           tot+=max(abs(points[i+1][0]-points[i][0]),abs(points[i+1][1]-points[i][1]));
        }
        return tot;
    }
};