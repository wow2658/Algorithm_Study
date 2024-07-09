#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int n, maxcnt, maxlimit;
int board[102][102];
bool vis[102][102];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void bfs(int i, int j, int limit)
{
    queue<pair<int, int>> q;
    vis[i][j] = true;
    q.push({ i, j });
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!vis[nx][ny] && board[nx][ny] > limit) // 핵심
            {
                vis[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            maxlimit = max(board[i][j], maxlimit); // 여기에서 미리 계산
        }
    }
    // 문제에서 limit가 주어지거나, limit를 찾는 문제가 아니다.
    // 모든 가능한 limit에 대해 안전한 영역의 수 계산
    for (int limit = 0; limit <= maxlimit; limit++)
    {
        // 새로운 limit 탐색 시작하면서 vis 초기화
        for (int i = 0; i < n; i++)
            fill(vis[i], vis[i] + n, false);

        // 이번 limit의 cnt 초기화
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] > limit && !vis[i][j]) // 핵심
                {
                    bfs(i, j, limit);
                    cnt++;
                }
            }
        }
        maxcnt = max(cnt, maxcnt);
    }
    cout << maxcnt;
}
