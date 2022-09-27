class Solution {
public:
    bool visited[301][301] = {0};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, grid);
                }
            }
        }

        return ans;
    }

    void bfs (int x, int y, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({x, y});

        while (!q.empty()) {
            pair<int, int> cell;
            cell = q.front();
            q.pop();
            x = cell.first;
            y = cell.second;
            visited[x][y] = true;
            for (int k = 0; k < 4; k++) {
                int a = x + dx[k];
                int b = y + dy[k];
                if (a < 0 || a >= grid.size() || b < 0 || b >= grid[0].size()) {
                    continue;
                }
                if (!visited[a][b] && grid[a][b] == '1') {
                    visited[a][b] = true;
                    q.push({a, b});
                }
            }

        }
    }
};