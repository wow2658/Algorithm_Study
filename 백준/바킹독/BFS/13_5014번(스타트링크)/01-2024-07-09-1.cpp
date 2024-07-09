#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int dist[1000002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> f >> s >> g >> u >> d;
	// 1층부터 f층 포함까지
	fill(dist + 1, dist + f + 1, -1);

	queue<int> q;
	dist[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		// U버튼은 위로 U층을 가고 D버튼은 아래로 D층. 즉, 껑충껑충 다닌다.
		for (auto& nxt : { cur + u,cur - d })
		{
			// f층 포함, 건물은 1층부터 시작
			if (nxt > f || nxt <= 0 || dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	if (dist[g] == -1)
		cout << "use the stairs";
	else cout << dist[g];
	return 0;
}