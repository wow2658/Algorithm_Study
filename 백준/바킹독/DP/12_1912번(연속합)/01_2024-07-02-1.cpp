#include <iostream>
using namespace std;

int n;
int a[100010];
int d[100010]; // d[i] : i번째 항으로 끝나는 연속합 중 최대

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
        d[i] = max(0, d[i - 1]) + a[i]; // 1. a[i-1]가 음수인것을 거르는게 아니다.
                                        // 2. 연속합의 결과가 음수인것은 이미 가망이 없다.
                                        // 3. 0으로 초기화해서 리세마라 하도록 한다.
                                        // 4. 이러저러한 다양한 경우의수는 이미 d[i-1]에 함축되어 녹아들어있다.
                                        // 5. 따라서, 바로 전의 누적합과 현재값의 합만 바라보도록 한다.



    cout << *max_element(d + 1, d + n + 1);
}