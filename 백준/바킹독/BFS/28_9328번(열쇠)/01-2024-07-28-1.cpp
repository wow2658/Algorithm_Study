#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

// 이동 방향 배열 (상, 하, 좌, 우)
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
const int MX = 120; // 최대 빌딩 크기 + 가장자리 여유 공간
int t, h, w; // 테스트 케이스 수, 빌딩 높이, 빌딩 너비
string keystr; // 상근이가 이미 가지고 있는 열쇠들
char board[MX][MX]; // 빌딩의 상태
int vis[MX][MX]; // 방문 여부

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t; // 테스트 케이스 수 입력
    while (t--)
    {
        cin >> h >> w; // 빌딩의 높이와 너비 입력
        queue<pair<int, int>> Q; // BFS를 위한 큐
        queue<pair<int, int>> door[26]; // 방문하지 못한 문들의 좌표 저장 큐
        int key[26] = {}; // 열쇠 보유 여부 (a-z)
        int cnt = 0; // 훔칠 수 있는 문서 개수

        // 초기화
        for (int i = 0; i <= h + 1; i++)
        {
            fill(vis[i], vis[i] + w + 2, 0); // 방문 여부 초기화
            fill(board[i], board[i] + w + 2, 0); // 빌딩 상태 초기화
        }

        // 빌딩 상태 입력
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> board[i][j];
            }
        }

        cin >> keystr; // 초기 열쇠들 입력

        // 초기 열쇠들 설정
        for (auto c : keystr)
        {
            if (c != '0') // '0'이 아니면
            {
                key[c - 'a'] = 1; // 해당 열쇠 보유
            }
        }

        Q.push({ 0, 0 }); // 빌딩 외부에서 시작
        vis[0][0] = 1; // 시작점 방문 표시

        // BFS 시작
        while (!Q.empty())
        {
            auto cur = Q.front(); Q.pop(); // 현재 위치

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                // 범위를 벗어나는 경우 무시
                if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1)
                {
                    continue;
                }
                // 이미 방문했거나 벽인 경우 무시
                if (vis[nx][ny] || board[nx][ny] == '*')
                {
                    continue;
                }

                vis[nx][ny] = 1; // 방문 표시

                // 열쇠인 경우
                if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z')
                {
                    int k = board[nx][ny] - 'a'; // 열쇠 인덱스 계산
                    key[k] = 1; // 열쇠 획득
                    // 해당 열쇠로 열 수 있는 문들 방문
                    while (!door[k].empty())
                    {
                        auto ndoor = door[k].front(); door[k].pop();
                        Q.push({ ndoor.X, ndoor.Y });
                    }
                }
                // 문인 경우
                else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z')
                {
                    int k = board[nx][ny] - 'a' + 32; // 대문자를 소문자로 변환하여 인덱스 계산
                    if (!key[k]) // 해당 열쇠가 없으면
                    {
                        door[k].push({ nx, ny }); // 문 위치 저장
                        continue;
                    }
                }
                // 문서인 경우
                else if (board[nx][ny] == '$')
                {
                    cnt++; // 문서 획득
                }

                Q.push({ nx, ny }); // 다음 위치 추가
            }
        }

        cout << cnt << "\n"; // 훔친 문서 개수 출력
    }
}

