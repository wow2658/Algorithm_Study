#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;        // 맵의 크기와 부술 수 있는 벽의 최대 개수를 저장할 변수
string board[1002]; // 맵을 저장할 배열 (최대 크기보다 조금 크게 잡음)
// x, y, 부순 횟수를 저장할 배열
int dist[1002][1002][12];    // 거리 배열, 부순 벽의 개수를 세 번째 차원으로 가짐
int dx[4] = { 1, 0, -1, 0 }; // 이동 방향을 나타내는 배열 (상하좌우)
int dy[4] = { 0, 1, 0, -1 }; // 이동 방향을 나타내는 배열 (상하좌우)

int main(void)
{
    ios::sync_with_stdio(0); // C 표준 입출력의 동기화를 끊음
    cin.tie(0); // cin의 성능을 높이기 위해 사용

    cin >> n >> m >> k; // n: 행의 수, m: 열의 수, k: 부술 수 있는 벽의 최대 개수
    for (int i = 0; i < n; i++)
    {
        cin >> board[i]; // 맵 입력 받기 string
    }

    // [x좌표, y좌표, 부순 횟수]로 큐를 구성한다.
    queue<tuple<int, int, int>> q; // 큐 생성, 좌표와 벽을 부순 횟수를 저장
    q.push({ 0, 0, 0 }); // 시작점 (0, 0)과 부순 벽의 개수 0을 큐에 삽입
    dist[0][0][0] = 1;   // 시작점의 거리 값을 1로 설정

    while (!q.empty()) // 큐가 비어있지 않은 동안 반복
    {
        int x, y, w;
        tie(x, y, w) = q.front(); // 큐의 front 값을 가져와 x, y, w에 할당
        q.pop(); // 큐의 front 값을 제거

        if (x == n - 1 && y == m - 1) // 도착점에 도달했을 경우
        {
            cout << dist[x][y][w] << '\n'; // 현재 거리 값을 출력하고 종료
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) // 상하좌우 4 방향으로 이동 시도
        {
            int nx = x + dx[dir]; // 이동 후 새로운 x 좌표
            int ny = y + dy[dir]; // 이동 후 새로운 y 좌표

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 맵의 범위를 벗어난 경우
                continue; // 무시하고 다음 방향으로

            int nw = w; // 현재 부순 벽의 개수

            if (board[nx][ny] == '1') // 이동할 위치가 벽인 경우
                nw++; // 부순 횟수를 증가

            if (nw > k || dist[nx][ny][nw] > 0) // 부순 횟수가 k를 초과하거나 이미 방문한 경우
                continue; // 무시하고 다음 방향으로

            dist[nx][ny][nw] = dist[x][y][w] + 1; // 새로운 위치의 거리 값 갱신
            q.push({ nx, ny, nw }); // 새로운 위치와 부순 횟수를 큐에 삽입
        }
    }

    cout << -1; // 도착점에 도달할 수 없는 경우 -1을 출력
}

