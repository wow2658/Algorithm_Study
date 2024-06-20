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
    int tot = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        tot += s[i];
    }

    if (n <= 2) 
    {
        cout << tot;
        return 0;
    }

    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    
    for (int i = 4; i <= n - 1; i++) 
    // n번째까지가 아니라 네거티브하게 n-1까지 고려하는것 명심
        d[i] = min(d[i - 2], d[i - 3]) + s[i];  
    // 안밟는다는 행위는 곧 계단을 망치로 부셔버린다고 생각하자
    // 연속 세번을 밟게 하지 않으려면 i-3라도 부셔서 흐름을 끊는 경우로 납득하자
    // d[i-1]도 안밟으면 d[i-2]에서 한번에 3계단을 도약해야해서 근본 규칙 위배 
    cout << tot - min(d[n - 1], d[n - 2]);      
    // positive max = total - negative min
}


#if 0
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
    for (int i = 1; i <= n; i++) 
        cin >> s[i];

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
    // d[i-1] 자체는 껑충과 따닥을 모두 포함하는데 따닥의 경우를 빼고 껑충만 뽑아 쓰는것이다
    cout << d[n];
    return 0;
}
#endif