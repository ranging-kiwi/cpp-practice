#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int bfs_count_weeds(int startX, int startY, vector<vector<bool>>& can_reach_start) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int weeds = 0;
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        if (grid[curr.first][curr.second] == '!') {
            weeds++;
        }
        
        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return weeds;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (!(cin >> n >> m)) return 0;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));
    int startX = -1, startY = -1;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '@') {
                startX = i;
                startY = j;
            }
        }
    }
    if (startX != -1) {
        cout << bfs_count_weeds(startX, startY, visited) << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
