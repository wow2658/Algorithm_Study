#include <iostream>
#include <queue>
#include <tuple>
using namespace std;


int board[202][202];
int vis[32][202][202]; // 방문 상태 저장 배열, [말 움직임 횟수][x 좌표][y 좌표]
int dmx[4] = { 0, 0, 1, -1 };
int dmy[4] = { 1, -1, 0, 0 };
int dkx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 }; // 말의 이동을 위한 x 변화량
int dky[8] = { 1, -1, 2, -2, 2, -2, 1, -1 }; // 말의 이동을 위한 y 변화량
queue<tuple<int, int, int>> Q; // BFS를 위한 큐, (말의 이동 횟수, x 좌표, y 좌표)
int bX, bY, Kn; // 격자판의 가로 크기, 세로 크기, 말의 이동 가능 횟수

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> Kn >> bY >> bX; // 말의 이동 가능 횟수, 격자판의 세로 크기, 가로 크기 입력
    for (int i = 0; i < bX; i++)
    {
        for (int j = 0; j < bY; j++)
        {
            cin >> board[i][j]; // 격자판 상태 입력 (0: 평지, 1: 장애물)
        }
    }

    Q.push({ 0, 0, 0 }); // 시작점 (0, 0)과 말의 이동 횟수 0을 큐에 삽입
    vis[0][0][0] = 1;    // 시작점 방문 표시, 이동 횟수는 1로 시작

    //
    //초기 세팅 완료

    while (!Q.empty())
    {
        int vk, vx, vy;
        tie(vk, vx, vy) = Q.front(); // 큐의 앞 요소 가져오기 (현재 말의 이동 횟수, x 좌표, y 좌표)
        Q.pop(); // 큐에서 제거

        // 현재 상태 출력
        cout << "현재 위치: (" << vx << ", " << vy << "), 말 이동 횟수: " << vk << ", 동작 수: " << vis[vk][vx][vy] - 1 << '\n'; // 맨처음을 1로 시작해서 보정


        if (vk < Kn) // 말의 이동 가능 횟수가 남아 있을 때
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = vx + dkx[i], ny = vy + dky[i]; // 새로운 위치 계산
                if (nx < 0 || ny < 0 || nx >= bX || ny >= bY) continue; // 격자판을 벗어나면 패스
                if (board[nx][ny]) continue;        // 장애물이 있으면 패스
                if (vis[vk + 1][nx][ny]) continue;  // 이미 방문한 곳(!= 0)이면 패스
                // vk는 소모성이기 때문에 +1이면 과거다.
                vis[vk + 1][nx][ny] = vis[vk][vx][vy] + 1; // 방문 표시 및 동작 수 증가
                Q.push({ vk + 1, nx, ny }); // 새로운 위치 큐에 삽입

                // 새로운 위치 상태 출력
                cout << "  말 이동: (" << nx << ", " << ny << "), 말 이동 횟수: " << vk + 1 << ", 동작 수: " << vis[vk + 1][nx][ny] - 1 << '\n';
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = vx + dmx[i], ny = vy + dmy[i];                 // 새로운 위치 계산
            if (nx < 0 || ny < 0 || nx >= bX || ny >= bY) continue; // 격자판을 벗어나면 패스
            if (board[nx][ny]) continue;        // 장애물이 있으면 패스
            if (vis[vk][nx][ny]) continue;      // 이미 방문한 곳이면 패스
            // 일반 이동은 vk를 소모하는 방식이 아니다.
            vis[vk][nx][ny] = vis[vk][vx][vy] + 1; // 방문 표시 및 동작 수 증가
            Q.push({ vk, nx, ny }); // 새로운 위치 큐에 삽입

            // 새로운 위치 상태 출력
            cout << "  일반 이동: (" << nx << ", " << ny << "), 말 이동 횟수: " << vk << ", 동작 수: " << vis[vk][nx][ny] - 1 << '\n';
        }
    }

    int ans = 0x7f7f7f7f; // 초기 최솟값 설정 (무한대 값으로 초기화)
    for (int i = 0; i < Kn + 1; i++) // K는 0이상 30이하의 정수라서 여유있다
    {
        if (vis[i][bX - 1][bY - 1])  // 우측하단 도착점이 0이 아니면
            ans = min(ans, vis[i][bX - 1][bY - 1]); // 다양한 i중에서 최소값을 찾기
        // vk를 사용하지 않은 경우가 더 빠를 수 있기 때문에 모든 경우를 고려해야 한다.
    }

    if (ans != 0x7f7f7f7f)
        cout << ans - 1; // 도착점에 도달한 경우 최소 동작 수 출력
    else cout << -1;     // 도착점에 도달하지 못한 경우 -1 출력
}
