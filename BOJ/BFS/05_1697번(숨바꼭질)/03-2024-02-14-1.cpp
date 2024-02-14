#include <bits/stdc++.h>
using namespace std;

int dist[100005];

int n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	queue<int> Q;
	Q.push(n);
	dist[n] = 1;

	while (dist[k] == 0)
	{
		auto cur = Q.front(); Q.pop();
		for (auto a : { cur - 1,cur + 1,2 * cur })
		{
			int nxt = a;
			if (nxt < 0 || nxt > 100000 || dist[nxt] != 0) continue;
			Q.push(nxt); dist[nxt] = dist[cur] + 1;
		}
	}

	cout << dist[k] - 1;
}