#include <iostream>
#include <vector>

using namespace std;

#define X first // pair에서 첫 번째 값을 의미
#define Y second // pair에서 두 번째 값을 의미

int dx[4] = { 1, 0, -1, 0 }; // 남쪽, 동쪽, 북쪽, 서쪽 순서의 x축 이동
int dy[4] = { 0, 1, 0, -1 }; // 남쪽, 동쪽, 북쪽, 서쪽 순서의 y축 이동
int n, m; // 사무실의 세로 크기 n과 가로 크기 m
int board1[10][10]; // 최초에 입력받은 사무실 상태를 저장할 배열
int board2[10][10]; // 사각 지대의 개수를 세기 위해 사용할 임시 배열
vector<pair<int, int>> cctv; // CCTV의 좌표를 저장할 벡터

// 좌표 (a, b)가 사무실 범위를 벗어났는지 확인하는 함수
bool OOB(int a, int b)
{
    return a < 0 || a >= n || b < 0 || b >= m; // 범위를 벗어나면 true를 반환
}

// (x, y)에서 dir 방향으로 진행하면서 벽을 만날 때까지 지나가는 모든 빈 칸을 7로 변경하는 함수
void upd(int x, int y, int dir)
{
    dir %= 4; // 방향을 4로 나눈 나머지로 계산하여 0~3 사이의 값으로 만듦
    while (1) // 무한 반복
    {
        x += dx[dir]; // x 좌표를 현재 방향으로 이동
        y += dy[dir]; // y 좌표를 현재 방향으로 이동
        if (OOB(x, y) || board2[x][y] == 6) // 범위를 벗어나거나 벽을 만나면 종료
        {
            return; // 함수 탈출
        }
        if (board2[x][y] != 0) // 해당 칸이 빈 칸이 아니라면 (CCTV가 있다면)
        {
            continue; // 다음 칸으로 넘어감
        }
        board2[x][y] = 7; // 빈 칸을 7로 변경 (감시 지역 표시)
    }
}

int main(void)
{
    ios::sync_with_stdio(0); // 입출력 속도 향상을 위해 사용
    cin.tie(0); // 입력과 출력의 묶음을 해제

    cin >> n >> m; // 사무실의 크기 입력 받음
    int mn = 0; // 사각 지대의 최소 크기를 저장할 변수

    // 사무실 상태를 입력받고, CCTV의 위치를 저장
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board1[i][j]; // 사무실 상태를 입력받음
            if (board1[i][j] != 0 && board1[i][j] != 6) // CCTV가 있는 경우
            {
                cctv.push_back({ i, j }); // CCTV의 좌표를 벡터에 저장
            }
            if (board1[i][j] == 0) // 빈 칸인 경우
            {
                mn++; // 사각 지대 크기를 증가시킴
            }
        }
    }

    // 모든 CCTV의 방향을 시뮬레이션
    for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) // 모든 방향 조합에 대해 브루트 포스 탐색
    {
        for (int i = 0; i < n; i++) // board2 배열을 초기화 (board1 복사)
        {
            for (int j = 0; j < m; j++)
            {
                board2[i][j] = board1[i][j];
            }
        }

        int brute = tmp; // 현재 방향 조합을 저장할 변수

        // 각 CCTV에 대해 방향을 설정
        for (int i = 0; i < cctv.size(); i++)
        {
            int dir = brute % 4; // 4방향 중 하나를 선택
            brute /= 4; // 다음 CCTV의 방향을 설정하기 위해 4로 나눔

            int x = cctv[i].X; // CCTV의 x 좌표
            int y = cctv[i].Y; // CCTV의 y 좌표

            // CCTV 종류에 따라 감시 영역 업데이트
            if (board1[x][y] == 1) // 1번 CCTV
            {
                upd(x, y, dir); // 한 방향만 감시
            }
            else if (board1[x][y] == 2) // 2번 CCTV
            {
                upd(x, y, dir); // 두 방향을 감시 (반대 방향)
                upd(x, y, dir + 2);
            }
            else if (board1[x][y] == 3) // 3번 CCTV
            {
                upd(x, y, dir); // 두 방향을 감시 (직각 방향)
                upd(x, y, dir + 1);
            }
            else if (board1[x][y] == 4) // 4번 CCTV
            {
                upd(x, y, dir); // 세 방향을 감시
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            }
            else // 5번 CCTV
            {
                upd(x, y, dir); // 네 방향을 감시
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }

        int val = 0; // 현재 경우에서의 사각 지대 크기 계산
        for (int i = 0; i < n; i++) // 사무실 전체를 순회
        {
            for (int j = 0; j < m; j++)
            {
                val += (board2[i][j] == 0); // 사각 지대인 경우 카운트 증가
            }
        }
        mn = min(mn, val); // 사각 지대의 최소 크기 갱신
    }

    cout << mn; // 사각 지대의 최소 크기 출력
}
