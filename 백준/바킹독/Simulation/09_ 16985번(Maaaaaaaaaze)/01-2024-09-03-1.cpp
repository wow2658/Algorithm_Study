#include <iostream>
#include <queue>
#include <tuple>

using namespace std; // 표준 네임스페이스 사용

// board[dir][i][j][k] :  i번째 판을 시계방향으로 dir번 돌렸을 때 (j, k)의 값
int board[4][5][5][5]; // 4가지 방향으로 회전한 5개 판의 상태를 저장
int maze[5][5][5]; // 현재 구성된 미로의 상태

// 6방향 이동을 위한 배열 (상, 하, 좌, 우, 앞, 뒤)
int dx[6] = { 1, 0, 0, 0, 0, -1 }; // x축 이동
int dy[6] = { 0, 1, -1, 0, 0, 0 }; // y축 이동
int dz[6] = { 0, 0, 0, 1, -1, 0 }; // z축 이동

// 미로를 탐색하여 최단 거리를 찾는 함수
int solve()
{
    int dist[5][5][5] = { 0, }; // 각 지점까지의 거리를 저장하는 3차원 배열

    // 시작점이나 도착점이 막혀있으면 불가능
    if (maze[0][0][0] == 0 || maze[4][4][4] == 0)
        return 9999; // 불가능한 경우 큰 값 반환

    queue<tuple<int, int, int>> q; // BFS를 위한 큐
    q.push({ 0,0,0 }); // 시작점 추가
    dist[0][0][0] = 1; // 시작점의 거리를 1로 설정

    while (!q.empty()) // 큐가 비어있지 않은 동안
    {
        tuple<int, int, int> cur = q.front(); q.pop(); // 현재 위치 꺼내기
        for (int dir = 0; dir < 6; dir++) // 6방향에 대해 반복
        {
            int x, y, z;
            tie(x, y, z) = cur; // 현재 위치의 좌표
            int nx = x + dx[dir]; // 새로운 x 좌표
            int ny = y + dy[dir]; // 새로운 y 좌표
            int nz = z + dz[dir]; // 새로운 z 좌표

            // 미로 범위를 벗어나면 건너뛰기
            if (0 > nx || 5 <= nx || 0 > ny || 5 <= ny || 0 > nz || 5 <= nz)
                continue;

            // 이동할 수 없는 칸이거나 이미 방문한 칸이면 건너뛰기
            if (maze[nx][ny][nz] == 0 || dist[nx][ny][nz] != 0)
                continue;

            // 도착점에 도달하면 현재까지의 거리 반환
            if (nx == 4 && ny == 4 && nz == 4)
                return dist[x][y][z];

            dist[nx][ny][nz] = dist[x][y][z] + 1; // 새 위치의 거리 갱신
            q.push({ nx,ny,nz }); // 새 위치를 큐에 추가
        }
    }

    // 도착점에 도달할 수 없는 경우
    return 9999; // 불가능한 경우 큰 값 반환
}

int main()
{
    ios::sync_with_stdio(0); // C++의 입출력 속도 향상
    cin.tie(0); // cin과 cout의 묶음을 풀어 속도 향상

    // 입력 받기 및 회전된 판 생성
    for (int i = 0; i < 5; i++) // 5개의 판에 대해 반복
    {
        // 원본 판 입력
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> board[0][i][j][k]; // 원본 판 입력 받기

        // 90도 회전
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[1][i][j][k] = board[0][i][4 - k][j];

        // 180도 회전
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[2][i][j][k] = board[1][i][4 - k][j];

        // 270도 회전
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[3][i][j][k] = board[2][i][4 - k][j];
    }

    int order[5] = { 0,1,2,3,4 }; // 판을 쌓는 순서
    int ans = 9999; // 최소 이동 횟수 (초기값은 매우 큰 수)

    // 모든 가능한 판 순서에 대해 탐색
    do
    {
        // 각 판의 4가지 회전 상태에 대해 탐색 (4^5 = 1024가지)
        for (int tmp = 0; tmp < 1024; tmp++)
        {
            int brute = tmp; // 5개의 판에 대해 회전 상태를 정해주기 위한 변수
            for (int i = 0; i < 5; i++) // 5개의 판에 대해 반복
            {
                int dir = brute % 4; // 현재 판의 회전 상태 (0, 1, 2, 3)
                brute /= 4; // 다음 판을 위해 brute 갱신
                for (int j = 0; j < 5; j++)
                    for (int k = 0; k < 5; k++)
                        maze[i][j][k] = board[dir][order[i]][j][k]; // 현재 미로 상태 구성
            }
            ans = min(ans, solve()); // 최소 이동 횟수 갱신
        }
    } while (next_permutation(order, order + 5)); // 다음 판 순서 생성

    // 불가능한 경우 -1 출력
    if (ans == 9999)
        ans = -1;

    cout << ans; // 결과 출력

    return 0; // 프로그램 종료
}