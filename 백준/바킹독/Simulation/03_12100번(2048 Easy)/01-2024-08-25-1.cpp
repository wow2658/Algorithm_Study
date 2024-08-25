#include <iostream>
#include <queue>

using namespace std;

int board1[21][21]; // 원본 보드를 저장할 배열
int board2[21][21]; // 변형된 보드를 저장할 배열
int n; // 보드의 크기

// board2 배열을 시계 방향으로 90도 회전하는 함수
void rotate()
{
    int tmp[21][21]; // 회전된 결과를 임시로 저장할 배열
    for (int i = 0; i < n; i++) // 보드의 각 행에 대해
    {
        for (int j = 0; j < n; j++) // 보드의 각 열에 대해
        {
            tmp[i][j] = board2[i][j]; // 원본 배열의 값을 임시 배열에 복사
        }
    }
    for (int i = 0; i < n; i++) // 회전된 배열을 board2에 다시 저장
    {
        for (int j = 0; j < n; j++)
        {
            board2[i][j] = tmp[n - 1 - j][i]; // 시계 방향으로 90도 회전
        }
    }
}

// dir 방향으로 보드를 기울이는 함수
void tilt(int dir)
{
    while (dir--) // 방향만큼 회전
    {
        rotate(); // 90도 회전
    }
    for (int i = 0; i < n; i++) // 보드의 각 행에 대해
    {
        int tilted[21] = {}; // 기울인 결과를 저장할 배열
        int idx = 0; // 현재 삽입할 위치를 나타내는 인덱스
        for (int j = 0; j < n; j++) // 보드의 각 열에 대해
        {
            if (board2[i][j] == 0) // 현재 칸이 빈 칸이면
            {
                continue; // 다음 칸으로 이동
            }
            if (tilted[idx] == 0) // 삽입할 위치가 비어있으면
            {
                tilted[idx] = board2[i][j]; // 현재 칸의 값을 삽입
            }
            else if (tilted[idx] == board2[i][j]) // 같은 값을 가진 블록이 충돌하면
            {
                tilted[idx++] *= 2; // 블록을 합치고 인덱스를 증가
            }
            else // 다른 값을 가진 블록이 충돌하면
            {
                tilted[++idx] = board2[i][j]; // 다음 위치에 값을 삽입
            }
        }
        for (int j = 0; j < n; j++) // 결과를 원래 보드에 덮어씀
        {
            board2[i][j] = tilted[j]; // 각 칸에 값을 저장
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0); // 입출력 속도 향상을 위한 설정
    cin.tie(0); // 입출력의 묶음을 해제

    cin >> n; // 보드의 크기를 입력
    for (int i = 0; i < n; i++) // 보드의 각 행에 대해
    {
        for (int j = 0; j < n; j++) // 보드의 각 열에 대해
        {
            cin >> board1[i][j]; // 보드의 값을 입력
        }
    }

    int mx = 0; // 최대 블록 크기를 저장할 변수
    for (int tmp = 0; tmp < 1024; tmp++) // 5번의 이동에 대한 모든 경우의 수를 시도
    {
        for (int i = 0; i < n; i++) // 보드를 초기 상태로 복사
        {
            for (int j = 0; j < n; j++)
            {
                board2[i][j] = board1[i][j]; // 원본 보드를 복사
            }
        }
        int brute = tmp; // 현재 이동 조합을 나타내는 변수
        for (int i = 0; i < 5; i++) // 최대 5번의 이동
        {
            int dir = brute % 4; // 방향 결정
            brute /= 4; // 다음 이동의 방향 계산을 위해 4로 나눔
            tilt(dir); // 해당 방향으로 보드를 기울임
        }
        for (int i = 0; i < n; i++) // 모든 칸을 순회하면서
        {
            for (int j = 0; j < n; j++)
            {
                mx = max(mx, board2[i][j]); // 최대 블록 크기 갱신
            }
        }
    }
    cout << mx; // 결과 출력
}

