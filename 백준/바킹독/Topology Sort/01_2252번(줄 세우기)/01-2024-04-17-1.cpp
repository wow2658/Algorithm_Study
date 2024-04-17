#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[32001]; // 이런 식으로 2차원을 활용하는건 처음이어서 당황했다. 배열인데 요소가 벡터인 것으로 이해하자.
int deg[32001];
int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);    // a에서 b로 뻗어 나간다는것
        deg[b]++;               // b의 indegree가 증가
    }
    queue<int> q;               // indegree 클럽
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur])            // cur에서 갈 수 있는곳 싹 뒤지기
        {
            deg[nxt]--;                     // cur이제 사라질거니까 니네 indegree하나씩 없앨거야
            if (deg[nxt] == 0) q.push(nxt); // 그중에 0클럽으로 승급되는 녀석 챙기기
        }
    }
}