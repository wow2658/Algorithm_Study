#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int n, m;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fill(d[i], d[i] + 1 + n, INF); // 0번 안쓰려고 1번~5번

    while (m--) 
    {
        int a, b, c;                   // a에서 b로 c비용
        cin >> a >> b >> c; 
        d[a][b] = min(d[a][b], c);     // 중복노선 중 최선  
    }

    for (int i = 1; i <= n; i++) d[i][i] = 0; // 셀프노선 대각선 0

    for (int k = 1; k <= n; k++)              // k 거쳐서
        for (int i = 1; i <= n; i++)          // i 부터
            for (int j = 1; j <= n; j++)      // j 까지
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);  // 더 나은거 있으면 교체

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}