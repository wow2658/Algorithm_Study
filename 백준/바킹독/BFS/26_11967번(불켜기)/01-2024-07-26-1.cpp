#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

// 각 방의 상태를 나타내는 배열: 불이 켜져 있으면 1, 꺼져 있으면 0
int board[101][101];
// 각 방의 방문 여부를 나타내는 배열: 방문했으면 true, 아니면 false
bool vis[101][101];
// 각 방에서 다른 방의 불을 켤 수 있는 관계를 저장하는 인접 리스트
vector<pair<int, int>> adj[101][101];
// 격자 내에서의 이동 방향: 오른쪽, 아래, 왼쪽, 위
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m; // 격자의 크기와 스위치의 개수

// 주어진 좌표가 격자 범위를 벗어나는지 확인하는 함수
bool OOB(int a, int b)
{
    // 1~n
    return a < 1 || a > n || b < 1 || b > n;
}

// 주어진 방이 (1,1)에서 도달 가능한 방인지 확인하는 함수
bool is_conn(pair<int, int> nxt)
{
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = nxt.X + dx[dir];
        int ny = nxt.Y + dy[dir];
        if (OOB(nx, ny)) continue;
        if (vis[nx][ny]) return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    // 입력을 받아 각 방에서 다른 방의 불을 켤 수 있는 관계를 설정
    while (m--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        adj[x][y].push_back({ a, b });
    }

    queue<pair<int, int>> Q;
    board[1][1] = 1; // 시작 방의 불을 켠다
    vis[1][1] = 1; // 시작 방을 방문했다고 표시
    Q.push({ 1, 1 }); // BFS를 시작하기 위해 시작 방을 큐에 넣음

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        // 현재 방에서 켤 수 있는 다른 방의 불을 켠다
        for (auto nxt : adj[cur.X][cur.Y])
        {
            if (vis[nxt.X][nxt.Y]) continue; // 이미 방문한 방은 건너뜀
            if (is_conn(nxt))
            {
                // 현재 방에서 도달할 수 있는 방이면
                vis[nxt.X][nxt.Y] = 1;
                Q.push({ nxt.X, nxt.Y });
            }
            board[nxt.X][nxt.Y] = 1; // 방의 불을 켬
        }

        // 상하좌우 인접한 방으로 이동하여 BFS를 계속 진행
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            Q.push({ nx, ny });
        }
    }

    // 불이 켜진 방의 개수를 세고 출력
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) ans += board[i][j];
    cout << ans;
}

/*
마치 인접 리스트 방식과 같이 연결 상태를 표현하는 것이 좋고 (adj 배열)
새롭게 불을 밝힌 방에 대해서 해당 방이 방문 가능한 곳인 경우에만 큐에 넣어주어야 한다.
*/
