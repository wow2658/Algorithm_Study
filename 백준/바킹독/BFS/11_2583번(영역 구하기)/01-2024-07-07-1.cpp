#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

// 방향 배열: 오른쪽, 위, 왼쪽, 아래 (동, 북, 서, 남)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int m, n, k;
int board[102][102];  // 격자판 정보 (직사각형 포함 여부)
int vis[102][102];    // 방문 여부를 저장하는 배열

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 행(m), 열(n), 직사각형 개수(k) 입력
    cin >> m >> n >> k;

    // K개의 직사각형 입력 및 격자판에 표시
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++)          // 행 범위
            for (int k = x1; k < x2; k++)      // 열 범위
                board[j][k] = 1;  // 직사각형 내부는 1로 채운다
    }

    int count = 0;    // 분리된 영역의 개수
    vector<int> ans;  // 각 영역의 넓이를 저장하는 벡터

    // 격자판을 순회하며 분리된 영역 찾기
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 이미 직사각형이 있거나 방문한 경우는 스킵
            if (board[i][j] == 1 || vis[i][j] == 1)
                continue;

            // BFS를 이용한 영역 탐색
            queue<pair<int, int>> Q;
            vis[i][j] = 1;  // 시작점 방문 표시
            Q.push({ i, j });
            int width = 1;  // 현재 영역의 넓이
            count++;        // 영역 개수 증가

            while (!Q.empty())
            {
                auto cur = Q.front();
                Q.pop();

                // 4방향 탐색
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    // 격자판 밖으로 나가면 스킵
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    // 직사각형이 있거나 이미 방문한 경우 스킵
                    if (board[nx][ny] == 1 || vis[nx][ny] == 1)
                        continue;

                    // 방문 처리 및 큐에 삽입
                    Q.push({ nx, ny });
                    vis[nx][ny] = 1;
                    width++;
                }
            }
            ans.push_back(width);  // 현재 영역의 넓이를 저장
        }
    }

    // 영역의 넓이를 오름차순으로 정렬
    sort(ans.begin(), ans.end());

    // 분리된 영역의 개수 출력
    cout << count << '\n';
    for (int i : ans)
        cout << i << ' ';  // 각 영역의 넓이 출력

    return 0;
}
