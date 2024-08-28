#include <iostream>
#include <queue>

using namespace std;  // std 네임스페이스 사용

bool isPuyo;  // 뿌요가 터졌는지 여부를 저장하는 변수
bool vis[12][6];  // 필드 방문 여부를 저장하는 배열
string board[12];  // 필드 상태를 저장하는 배열
int dx[] = { 1, 0, -1, 0 };  // x 방향으로의 이동을 위한 배열
int dy[] = { 0, 1, 0, -1 };  // y 방향으로의 이동을 위한 배열
int ans;  // 연쇄 횟수를 저장하는 변수

// vis 배열 초기화 함수
void resetVis()
{
    for (int i = 0; i < 12; ++i)  // 12줄을 순회하면서
    {
        for (int j = 0; j < 6; ++j)  // 각 줄의 6칸을 순회하면서
        {
            vis[i][j] = false;  // 모든 칸의 방문 여부를 false로 초기화
        }
    }
}

// bfs 탐색을 기반으로 같은 색의 뿌요를 지우는 함수
void puyo(int x, int y)
{
    vis[x][y] = true;  // 현재 위치를 방문했음을 표시
    char color = board[x][y];  // 현재 뿌요의 색깔을 저장
    queue<pair<int, int>> q;  // BFS를 위한 큐
    vector<pair<int, int>> tmp;  // 지울 뿌요의 위치를 저장할 벡터
    q.push({ x, y });  // 현재 위치를 큐에 삽입
    tmp.push_back({ x, y });  // 현재 위치를 벡터에 삽입

    while (!q.empty())  // 큐가 빌 때까지 반복
    {
        pair<int, int> cur = q.front();  // 큐의 맨 앞 요소를 가져옴
        q.pop();  // 큐의 맨 앞 요소를 제거
        for (int i = 0; i < 4; ++i)  // 4개의 방향을 순회하면서
        {
            int nx = cur.first + dx[i];  // 다음 x 좌표를 계산
            int ny = cur.second + dy[i];  // 다음 y 좌표를 계산
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)  // 필드를 벗어나는지 체크
            {
                continue;  // 범위를 벗어나면 무시
            }
            // 방문했거나, 빈 칸이거나, 색이 다를 경우 무시
            if (vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color)
            {
                continue;
            }
            vis[nx][ny] = true;  // 방문 여부를 true로 설정
            q.push({ nx, ny });  // 큐에 다음 위치를 삽입
            tmp.push_back({ nx, ny });  // 벡터에 다음 위치를 삽입
        }
    }

    // 4개 이상 연결되어 있을 경우 연결된 뿌요 삭제
    if (tmp.size() >= 4)
    {
        isPuyo = true;  // 뿌요가 터졌음을 표시
        for (auto cur : tmp)  // 벡터에 저장된 모든 위치에 대해
        {
            board[cur.first][cur.second] = '.';  // 해당 위치의 뿌요를 삭제
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);  // C++의 입출력 속도를 높임
    cin.tie(0);  // cin과 cout의 묶음을 풀어줌

    for (int i = 0; i < 12; ++i)  // 12줄을 순회하면서
    {
        cin >> board[i];  // 필드의 상태를 입력받음
    }

    do
    {
        isPuyo = false;  // 뿌요가 터졌는지 여부를 false로 초기화

        for (int i = 0; i < 6; ++i)  // 6개의 열을 순회하면서
        {
            // 필드의 빈 칸을 모두 뿌요 위로 올림
            for (int j = 10; j >= 0; --j)  // 아래에서부터 위로 순회
            {
                int tmp = j;  // 현재 위치를 임시 변수에 저장
                // 빈 칸일 경우 위치 변경
                while (tmp < 11 && board[tmp + 1][i] == '.')  // 아래 칸이 빈 칸일 때
                {
                    swap(board[tmp][i], board[tmp + 1][i]);  // 뿌요를 아래로 내림
                    ++tmp;  // 위치를 한 칸 아래로 이동
                }
            }
        }

        // 필드 상의 터져야 하는 모든 뿌요 처리
        for (int i = 0; i < 12; ++i)  // 12줄을 순회하면서
        {
            for (int j = 0; j < 6; ++j)  // 각 줄의 6칸을 순회하면서
            {
                if (!vis[i][j] && board[i][j] != '.')  // 방문하지 않았고, 빈 칸이 아닌 경우
                {
                    puyo(i, j);  // 뿌요를 터뜨림
                }
            }
        }

        if (isPuyo)  // 뿌요가 터졌다면
        {
            ++ans;  // 연쇄 수를 증가시킴
        }

        resetVis();  // 방문 배열을 초기화
    } while (isPuyo);  // 더 이상 뿌요가 터지지 않을 때까지 반복

    cout << ans;  // 연쇄 횟수를 출력
}

