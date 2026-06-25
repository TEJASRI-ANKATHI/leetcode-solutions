class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int r = front.first.first;
            int c = front.first.second;
            int t = front.second;

            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({{nr, nc}, t + 1});
                }
            }
        }

        if (fresh > 0) return -1;

        return time;
    }
};