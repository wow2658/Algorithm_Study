#include <iostream>
using namespace std;

int n;
int a[505][505], d[505][505];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) // 1층에1번 2층에2번
            cin >> a[i][j];

    d[1][1] = a[1][1];               // 맨처음 누적점수니까 첫빠따

    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
                                     // 문제 조건에서 위의 두갈래중에 하나로부터 오는거였으므로, 아직 효율 안따지고 닥치는대로 채우는 단계

    cout << *max_element(d[n] + 1, d[n] + n + 1);   // 1번부터 n번까지는 여러 경우의 수들이 포진되어있는데 그중의 최대


}