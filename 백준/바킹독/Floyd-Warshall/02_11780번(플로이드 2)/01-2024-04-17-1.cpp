#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int nxt[105][105];
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
        nxt[a][b] = b;                 // 맨처음에는 a->b 가는 길로 b면 오케이
    }

    for (int i = 1; i <= n; i++) d[i][i] = 0; // 셀프노선 대각선 0

    for (int k = 1; k <= n; k++)              // k 거쳐서
        for (int i = 1; i <= n; i++)          // i 부터
            for (int j = 1; j <= n; j++)      // j 까지
            {
                if (d[i][j] > d[i][k] + d[k][j])  // 더 최소인 결과 나오면 덮어쓰기
                {
                    d[i][j] = d[i][k] + d[k][j];  // 굳이 여기에 min 넣어야하나?
                    nxt[i][j] = nxt[i][k];        // 덮어쓸때 nxt도 업데이트하기. k열 고정인건 그려보면 안다.
                }
            }
            // d[i][j] = min(d[i][j], d[i][k] + d[k][j]);  // 더 나은거 있으면 교체

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == 0 || d[i][j] == INF) 
            {
                cout << "0\n"; continue;
            }
            vector<int> path;
            int st = i;
            while (st != j)         // 아직 도착안했으면
            {
                path.push_back(st); // 거쳐가는 길이니까 수집하고
                st = nxt[st][j];    // 어디로가야하는지? + 거기에서부터 시작해보자
            }
            path.push_back(j);      // 맨마지막 도착지 넣으면 path완성!
            cout << path.size() << ' ';            // 최소 비용에 포함되어 있는 도시의 개수 
            for (auto x : path) cout << x << ' ';  // 그 다음, 도시 i에서 도시 j로 가는 경로를 공백으로 구분해 출력한다.

            cout << '\n';
        }
    }
}