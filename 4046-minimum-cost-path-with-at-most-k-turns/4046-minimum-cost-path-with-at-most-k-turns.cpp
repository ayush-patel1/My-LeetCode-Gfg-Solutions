class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector dist(n, vector(m, vector(k + 1, vector<int>(5, INT_MAX))));

        dist[0][0][0][4] = grid[0][0];

        pq.push({grid[0][0], 0, 0, 0, 4});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int turns = cur[1];
            int r = cur[2];
            int c = cur[3];
            int prevDir = cur[4];

            if (cost != dist[r][c][turns][prevDir])
                continue;

            if (r == n - 1 && c == m - 1)
                return cost;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int newTurns = turns;

                if (prevDir != 4 && prevDir != d)
                    newTurns++;

                if (newTurns > k)
                    continue;

                int newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc][newTurns][d]) {
                    dist[nr][nc][newTurns][d] = newCost;

                    pq.push({newCost, newTurns, nr, nc, d});
                }
            }
        }

        return -1;
    }
};