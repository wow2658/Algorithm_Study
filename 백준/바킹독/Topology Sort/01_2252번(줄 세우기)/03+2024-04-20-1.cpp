#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[32002];
int deg[32002];
queue<int> q;
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	// 0클럽 수집
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0) q.push(i);

	}

	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur])			// 애초에 deg 정리할 작정으로 루프를 도는 것이니까
		{
			deg[nxt]--;	// 디버깅으로 잡아낸 서순
			if (deg[nxt] == 0) q.push(nxt); // 먼저 갔다고 치고 deg 까야 q에 갈 기회가 생긴다.
		}
	}
}
