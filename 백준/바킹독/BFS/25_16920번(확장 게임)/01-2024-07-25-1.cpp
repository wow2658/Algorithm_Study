#include <bits/stdc++.h>
using namespace std;

int canExtend[1000][1000]; // 성이 확장 가능한지 여부를 저장하는 배열
int step[10]; // 각 플레이어의 최대 이동 거리
int area[10]; // 각 플레이어가 점령한 성의 개수
int dx[4] = { 0, 0, 1, -1 }; // 이동 방향 (상, 하, 좌, 우)
int dy[4] = { 1, -1, 0, 0 };
queue<tuple<int, int, int>> q[10]; // 각 플레이어의 BFS 큐

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, P; // 격자판의 크기 N, M과 플레이어의 수 P
    cin >> N >> M >> P;

    // 각 플레이어의 이동 제한 횟수 입력
    for (int i = 1; i <= P; i++)
    {
        cin >> step[i];
    }

    // 맵 입력
    char ch;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            cin >> ch;
            if (ch == '.')
            {
                canExtend[i][j] = 1; // 빈 칸
            }
            else if (ch == '#')
            {
                canExtend[i][j] = 0; // 벽
            }
            else
            {
                canExtend[i][j] = 0; // 플레이어의 성
                q[ch - '0'].push({ i, j, 0 }); // 각 플레이어의 초기 영토 기록
                area[ch - '0'] += 1; // 초기 성의 개수를 증가
            }
        }
    }

    // 게임 시작
    while (true) 
    {
        bool isExtend = false; // 이번 턴에 확장이 있었는지 여부

        // 1~P번 플레이어의 순차적인 영토 확장
        for (int i = 1; i <= P; i++) 
        {
            queue<tuple<int, int, int>> nextq; // 다음 턴에 확장을 고려할 영토 기록
            while (!q[i].empty())
            {
                int curx, cury, curstep;
                tie(curx, cury, curstep) = q[i].front();
                q[i].pop();

                // 현재 위치에서 최대 이동 거리를 초과했는지 확인
                if (curstep >= step[i])
                {
                    nextq.push({ curx, cury, 0 });
                    continue;
                }

                // 현재 위치에서 네 방향으로 확장 시도
                for (int dir = 0; dir < 4; dir++)
                {
                    int x = curx + dx[dir];
                    int y = cury + dy[dir];

                    // 격자판의 범위를 벗어나면 무시
                    if (x < 0 || x >= N || y < 0 || y >= M) continue;
                    // 벽이거나 이미 확장된 칸이면 무시
                    if (!canExtend[x][y]) continue;

                    // 새로운 위치로 확장
                    q[i].push({ x, y, curstep + 1 });
                    canExtend[x][y] = 0; // 확장 불가능하도록 설정
                    area[i]++; // 플레이어의 성 개수 증가
                    isExtend = true; // 확장이 있었음을 표시
                }
            }
            q[i] = nextq; // 다음 턴에 확장을 고려할 큐 업데이트
        }

        // 이번 턴에 확장이 없었으면 게임 종료
        if (!isExtend) break;
    }

    // 각 플레이어의 최종 영토 출력
    for (int i = 1; i <= P; i++) 
    {
        cout << area[i] << " ";
    }
}
