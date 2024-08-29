#include <iostream>

using namespace std;

// 4개의 톱니바퀴 상태를 저장하는 문자열 배열
// 각 문자열은 8개의 문자(0 또는 1)로 구성됨
// 0은 N극, 1은 S극을 나타냄
string board[4];

// x : 회전시킬 톱니바퀴 번호 (0-based index)
// dir : 회전 방향 (1: 시계 방향, -1: 반시계 방향)
// 하나의 톱니바퀴 회전과 그로 인한 연쇄 반응을 처리하는 함수
void go(int x, int dir)
{
    // 각 톱니바퀴의 회전 방향을 저장하는 배열
    // 0: 회전 안 함, 1: 시계 방향, -1: 반시계 방향
    int dirs[4] = {};

    // 현재 톱니바퀴의 회전 방향 설정
    dirs[x] = dir;

    // 왼쪽으로 회전 전파
    // 맞닿은 톱니의 극이 다르면 반대 방향으로 회전
    int idx = x;
    while (idx > 0 && board[idx][6] != board[idx - 1][2])
    {
        dirs[idx - 1] = -dirs[idx];
        idx--;
    }

    // 오른쪽으로 회전 전파
    // 맞닿은 톱니의 극이 다르면 반대 방향으로 회전
    idx = x;
    while (idx < 3 && board[idx][2] != board[idx + 1][6])
    {
        dirs[idx + 1] = -dirs[idx];
        idx++;
    }

    // 모든 톱니바퀴 회전 실행
    for (int i = 0; i < 4; i++)
    {
        if (dirs[i] == -1)
            // 반시계 방향 회전 (왼쪽으로 1칸)
            rotate(board[i].begin(), board[i].begin() + 1, board[i].end());
        else if (dirs[i] == 1)
            // 시계 방향 회전 (오른쪽으로 1칸, 즉 왼쪽으로 7칸)
            rotate(board[i].begin(), board[i].begin() + 7, board[i].end());
    }
}

int main(void)
{
    // 입출력 최적화
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 4개의 톱니바퀴 초기 상태 입력
    // 각 톱니바퀴는 8개의 톱니로 구성 (12시방향부터 시계방향으로)
    for (int i = 0; i < 4; i++)
        cin >> board[i];

    // 회전 횟수 입력
    int k;
    cin >> k;

    // k번 회전 실행
    while (k--)
    {
        int x, dir;
        cin >> x >> dir;
        // 톱니바퀴 번호는 1-based이므로 0-based로 변환
        go(x - 1, dir);
    }

    // 최종 상태에서 점수 계산
    int ans = 0;
    for (int i = 0; i < 4; i++)
        if (board[i][0] == '1')  // 12시 방향이 S극(1)인 경우
            ans += (1 << i);  // 2^i 점 추가 (1번:1점, 2번:2점, 3번:4점, 4번:8점)

    // 최종 점수 출력
    cout << ans;
}

/*
STL의 rotate 함수를 사용하여 톱니바퀴의 회전을 효율적으로 구현했습니다.
rotate(first, middle, last)는 [first, last) 범위의 원소들을 middle을 첫 원소로 하도록 회전시킵니다.
*/
