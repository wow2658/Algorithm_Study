#include <iostream>

using namespace std;

int N;
int paper[2200][2200];                      //3^7 = 2187
int cnt[3];                                 //-1, 0, 1로 채워진 종이 갯수

bool check(int x, int y, int n)             // main 첫스타트 00n은 n이 엉터리라 무쓸모
{
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (paper[x][y] != paper[i][j])
                return false;
    return true;                            // 재귀로 인해 들어온 solve부터 진짜 유의미
}
void solve(int x, int y, int z)
{
    if (check(x, y, z))
    {
        cnt[paper[x][y] + 1] += 1;          // 종이->index, -1->0, 0->1, 1->2
        return;                             // void 탈출
    }

    int n = z / 3;                          // 종이를 같은 크기의 종이 9개로 자르자고 했으니까
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            solve(x + i * n, y + j * n, n); // 0 3 6 부분 정복하겠다.
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];             // 정석대로 paper 2차원 보드 초기화
    solve(0, 0, N);                         // 스타팅
    for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";
}