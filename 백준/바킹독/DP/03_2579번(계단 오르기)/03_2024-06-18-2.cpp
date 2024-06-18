#include <iostream>

using namespace std;

int s[305];
int n;
int d[305];

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
    d[1] = s[1];
    if (n > 1) d[2] = s[2] + s[1];
    if (n > 2) d[3] = s[3] + max(s[2], s[1]);

    for (int i = 4; i <= n; i++)
        d[i] = s[i] + max(s[i - 1] + d[i - 3], d[i - 2]);
    // d[i - 1] + s[i]를 직접 사용하지 않고 s[i - 1] + d[i - 3] + s[i]로 쓴 이유는
    // "연속된 세 개의 계단을 모두 밟아서는 안 된다"는 규칙을 준수하기 위함
    cout << d[n];
    return 0;
}