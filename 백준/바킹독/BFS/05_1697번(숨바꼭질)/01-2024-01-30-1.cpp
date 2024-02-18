#include <bits/stdc++.h>
using namespace std;

int N, K;
int dist[100002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	fill(dist, dist + 100001, -1);
	queue<int> Q;
	Q.push(N); dist[N] = 0;

	while (dist[K] < 0) // 꽉 채우는게 목표였으면 !Q.empty()
	{
		auto cur = Q.front(); Q.pop();
		for (int nx : {cur - 1, cur + 1, 2 * cur})
		{
			if (nx < 0 || nx>100000 || dist[nx] >= 0) continue;
			Q.push(nx); dist[nx] = dist[cur] + 1;
		}
	}
	cout << dist[K];


}