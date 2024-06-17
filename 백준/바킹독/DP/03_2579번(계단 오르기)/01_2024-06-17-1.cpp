#include <iostream>

using namespace std;

int s[305];
int n;
int d[305][3];     //d[i][j] 현재까지 j개의 계단을 연속해서 밟았고 i번째 계단까지 올라섰을때의 점수 합의 최대값
                   //단, i번째 계단은 반드시 밟아야 함

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> s[i];
    if (n == 1)
    {
        cout << s[1];
        return 0;
    }
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1] + s[2];
    for (int i = 3; i <= n; i++)
    {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];
        d[i][2] = d[i - 1][1] + s[i];
    }
    cout << max(d[n][1], d[n][2]);
}
}