#include <bits/stdc++.h>
using namespace std;

int dist[100002];
int n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	fill(dist, dist + 100001, -1);
	queue<int> Q;
	Q.push(n); dist[n] = 0;
	while (dist[k] < 0)
	{
		auto cur = Q.front(); Q.pop();
		for (int nxt : {cur + 1, cur - 1, 2 * cur})
		{
			if (nxt < 0 || nxt>100000 || dist[nxt] > -1) continue;
			Q.push(nxt); dist[nxt] = dist[cur] + 1;
		}
	}
	cout << dist[k];
}
