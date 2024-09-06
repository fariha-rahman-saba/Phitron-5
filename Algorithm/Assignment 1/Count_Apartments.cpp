#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.');
}

void dfs(int si, int sj) {
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++) {
        int ci = si + dx[i];
        int cj = sj + dy[i];
        if (valid(ci, cj) && !vis[ci][cj]) {
            dfs(ci, cj);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
