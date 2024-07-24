#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;  // 지도 크기와 부술 수 있는 최대 벽의 수
string board[1002];  // 지도 정보를 담을 배열
int dist[1002][1002][12][2];  // 거리 정보를 담을 4차원 배열 (x, y, 부순 벽의 수, 낮/밤 여부)
int dx[4] = { 1, 0, -1, 0 };  // 이동 방향 (하, 우, 상, 좌)
int dy[4] = { 0, 1, 0, -1 };  // 이동 방향 (하, 우, 상, 좌)

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;  // 지도 크기와 최대 부술 수 있는 벽의 수 입력
    for (int i = 0; i < n; i++)
        cin >> board[i];  // 지도 정보 입력

    queue<tuple<int, int, int, int>> q;  // BFS를 위한 큐 (x, y, 부순 벽의 수, 낮/밤 여부)
    q.push({ 0, 0, 0, 0 });  // 시작점 (0, 0)에서 부순 벽의 수 0, 낮(0)으로 시작
    dist[0][0][0][0] = 1;  // 시작점의 거리 정보 초기화

    while (!q.empty())
    {
        int x, y, w, t;
        tie(x, y, w, t) = q.front();  // 현재 위치 (x, y), 부순 벽의 수 w, 낮/밤 t
        q.pop();

        // 목표 지점에 도달한 경우
        if (x == n - 1 && y == m - 1)
        {
            cout << dist[x][y][w][t] << '\n';  // 현재까지의 거리 출력
            return 0; // 종료
        }

        // 인접한 4방향에 대해 탐색
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];  // 다음 위치 계산
            int ny = y + dy[dir];  // 다음 위치 계산
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)  // 지도 범위를 벗어나는 경우
                continue;

            // 빈 곳으로 이동하는 경우
            if (board[nx][ny] == '0')
            {
                int nw = w;  // 부순 벽의 수는 그대로
                int nt = 1 - t;  // 낮/밤 변경
                if (dist[nx][ny][nw][nt] > 0) continue;  // 이미 방문한 경우 무시
                dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;  // 거리 갱신
                q.push({ nx, ny, nw, nt });  // 큐에 추가
            }
            // 이동할 위치가 벽인 경우
            else
            {
                if (w == k) continue;  // 최대 벽을 부순 경우 더 이상 벽을 부술 수 없음
                if (t == 0) // 낮인 경우 벽을 부수고 이동
                {
                    int nw = w + 1;  // 부순 벽의 수 증가
                    int nt = 1 - t;  // 낮/밤 변경
                    if (dist[nx][ny][nw][nt] > 0) continue;  // 이미 방문한 경우 무시
                    dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;  // 거리 갱신
                    q.push({ nx, ny, nw, nt });  // 큐에 추가
                }
                else // 밤인 경우 벽을 부술 수 없으므로 기다림
                {
                    int nt = 1 - t;  // 낮/밤 변경
                    if (dist[x][y][w][nt] > 0) continue;  // 이미 방문한 경우 무시
                    dist[x][y][w][nt] = dist[x][y][w][t] + 1; // 다음 좌표가 (nx, ny, nw, nt)가 아닌 (x, y, w, nt)라는 점에 주의한다.
                    q.push({ x, y, w, nt });  // 큐에 추가 (현재 위치에서 낮/밤만 변경)

                }
            }
        }
    }

    // 목표 지점에 도달할 수 없는 경우
    cout << -1;  // -1 출력
    return 0;
}
