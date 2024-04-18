#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[32'002];
int deg[32'002];
int n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		adj[a].push_back(b);
		++deg[b];
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (0 == deg[i]) q.push(i);
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur])
		{
			--deg[nxt];
			if (0 == deg[nxt])
				q.push(nxt); // q.push(cur); 조심
		}
	}

}