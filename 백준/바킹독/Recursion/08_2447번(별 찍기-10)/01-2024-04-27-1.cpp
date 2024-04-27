#include <iostream>

using namespace std;

char board[2300][2300];     // 3^7 = 2187

// solve(n, x, y) : board[x][y] to board[x+n-1][y+n-1]에 올바르게 '*'과 ' '을 넣는 함수
void solve(int n, int x, int y)
{
    if (n == 1)             // 최소단위
    {
        board[x][y] = '*';  // 찍고
        return;             // 탈출
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            solve(n / 3, x + n / 3 * i, y + n / 3 * j); // 분할할 때 자주 보던 양식
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        fill(board[i], board[i] + n, ' ');

    solve(n, 0, 0);

    for (int i = 0; i < n; i++)
        cout << board[i] << '\n';   // 2차원 배열의 [r]행 한줄 쫙
}
/*
board[...][n]에 NULL 대신 ' '이 들어있을 경우 뒤에 불필요한 공백이 추가로 출력될 수 있음. board는 전역 변수이기 때문에
초기 값이 전부 NULL이어서 잘 동작함.
*/