#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[20002];
const int INF = 0x3f3f3f3f;
int v, e, st;
int d[20002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> st;
	fill(d, d + v + 1, INF);
	while (e--)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[st] = 0;
	pq.push({ d[st],st });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;

		for (auto nxt : adj[cur.second])
		{
			/*
			if (d[nxt.second] <= d[cur.second] + nxt.first) 여기 틀림
			{
				d[nxt.second] = d[cur.second] + nxt.first;
				pq.push({ d[nxt.second],nxt.second });
			}
			차라리 continue로 거르거나
			*/
			if (d[nxt.second] > d[cur.second] + nxt.first)
			{
				d[nxt.second] = d[cur.second] + nxt.first;
				pq.push({ d[nxt.second],nxt.second });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}


}
