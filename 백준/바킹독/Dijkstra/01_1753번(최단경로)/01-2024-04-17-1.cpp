#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e, st; // 버텍스 엣지 스타트

// {비용, 정점 번호}
vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; // 최단 거리 테이블

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> st;
	fill(d, d + v + 1, INF);          // 1번~5번
	while (e--)
	{
		int u, v, w;
		cin >> u >> v >> w;           // u에서 v로 갈때 w 비용이 든다
		adj[u].push_back({ w,v });    // first 가중치, second 목적지
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // 최소힙

	d[st] = 0;
	// 우선순위 큐에 (0, 시작점) 추가
	pq.push({ d[st],st });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop(); // {비용, 정점 번호}    
		// 거리가 d에 있는 값과 다를 경우 넘어감 -> 이거 덕분에 fix없어도 됨
		if (d[cur.second] != cur.first) continue; // 기록되어 있는 가중치가, 지금 꺼낸 가중치랑 다르면 fake 

		for (auto nxt : adj[cur.second])          // 갈 수 있는곳 다 훑어!
		{
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			// cur를 거쳐가는 것이 더 작은 값을 가질 경우
			// d[nxt.second]을 갱신하고 우선순위 큐에 (거리, nxt.second)를 추가
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second],nxt.second }); // 갱신했을때만 추가하는 것
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}
}

// 많이 달라지긴 했다.
int V = 10;
void dijkstra_naive(int st)
{
	fill(d, d + V + 1, INF);
	d[st] = 0; 
	while (true)
	{
		int idx = -1;
		for (int i = 1; i <= V; i++)
		{
			if (fix[i]) continue;
			if (idx == -1)idx = i;
			else if (d[i] < d[idx] == INF) idx = i;
		}

		if (idx == -1 || d[idx] == INF) break; 

		fix[idx] = 1;
		for (auto nxt : adj[idx])
		{
			d[nxt.second] = min(d[nxt.second], d[idx] + nxt.first)
		}

	}
}