class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>> > pq;

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int e = node.first;
            int r = node.second.first;
            int c = node.second.second;

            if(r == n-1 && c == m-1)
                return e;

            for(int i=0;i<4;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){

                    int cur_e = max(e, abs(heights[r][c]-heights[nr][nc]));

                    if(dist[nr][nc] > cur_e){
                        dist[nr][nc] = cur_e;
                        pq.push({cur_e,{nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};