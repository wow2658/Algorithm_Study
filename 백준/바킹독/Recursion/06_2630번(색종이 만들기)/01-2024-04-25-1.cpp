#include <iostream>

using namespace std;

int N;
int paper[130][130];                        //2^7 = 128
int cnt[2];                                 //0흰 1파 

bool check(int x, int y, int n)             //저번 문제랑 똑같다. 이게 국룰인듯
{
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (paper[x][y] != paper[i][j])
                return false;
    return true;
}
void solve(int x, int y, int z)
{
    if (check(x, y, z))
    {
        cnt[paper[x][y]] += 1;
        return;
    }

    int n = z / 2;                          // 2분할
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            solve(x + i * n, y + j * n, n);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];             // 정석대로 paper 2차원 보드 초기화
    solve(0, 0, N);                         // 스타팅
    for (int i = 0; i < 2; i++) cout << cnt[i] << "\n";
}