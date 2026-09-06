class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        
        const long long INF = 1e18;

        vector<vector<vector<vector<long long>>>> dist(
            m, vector<vector<vector<long long>>>(
                n, vector<vector<long long>>(
                    5, vector<long long>(k + 1, INF)
                )
            )
        );

        using State = tuple<long long, int, int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        
        dist[0][0][4][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0, 4, 0});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [cost, r, c, dir, turns] = pq.top();
            pq.pop();

            if (cost != dist[r][c][dir][turns])
                continue;

            
            if (r == m - 1 && c == n - 1)
                return (int)cost;

            for (int nd = 0; nd < 4; nd++) {
                int nr = r + dr[nd];
                int nc = c + dc[nd];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                
                int newTurns = turns;

                if (dir != 4 && dir != nd) {
                    newTurns++;
                }

                if (newTurns > k)
                    continue;

                long long newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc][nd][newTurns]) {
                    dist[nr][nc][nd][newTurns] = newCost;
                    pq.push({
                        newCost,
                        nr,
                        nc,
                        nd,
                        newTurns
                    });
                }
            }
        }

        return -1;
    }
};