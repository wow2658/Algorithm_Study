#include <iostream>
using namespace std;

int n;
int a[1010], d[1010];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        d[i] = a[i];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i])                    // 증가하는 수열을 만드는것이 조건이었기 때문이다.
                d[i] = max(d[i], d[j] + a[i]);  // d[j]: 현재까지 구한 부분 수열 중에서, 
    //       마지막 원소가 a[j]인 증가하는 부분 수열의 최대 합.
    // 계속 변화하는, 즉 여러 d[j]중에 가장 가능성있어보이는 친구에게 투자하겠다는 느낌

    cout << *max_element(d, d + n);
}