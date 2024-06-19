#include <iostream>

using namespace std;

int s[305];
int n;
int d[305][3];

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

    for (int i = 3; i <= n; i++)
    {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];  // 그냥 껑충이랑 따닥 후 껑충
        d[i][2] = d[i - 1][1] + s[i];                    // 따닥결과는 껑충 고려 안하고 1가지 경우밖에 없음

    }
    cout << max(d[n][1], d[n][2]);
}