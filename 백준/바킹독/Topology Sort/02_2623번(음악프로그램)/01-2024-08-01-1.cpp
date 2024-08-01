#include <iostream>
#include <queue>
using namespace std;

int n, m;  // n: 가수의 수, m: 보조 PD의 수
int id[1002];  // indegree 배열
vector<int> adj[1002];  // 배열인데 요소가 벡터인 신기한 형태. 위상정렬의 시그니처인것 같다.
vector<int> sq;  // 결과를 저장할 벡터

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력 받기
	cin >> n >> m;

	int no, u, v;

	// 각 보조 PD의 순서 정보를 처리
	for (int i = 0; i < m; i++)
	{
		cin >> no;  // 현재 보조 PD가 담당한 가수의 수. no의 총합이 n보다 큰 경우가 있다. pd가 데려오는 가수가 중복이 허용되기 때문이다.

		if (no == 0)
		{
			continue;
		}

		cin >> u;  // 첫 번째 가수

		// 나머지 가수들에 대해 간선을 추가
		while (--no)
		{
			cin >> v;  // 다음 가수
			adj[u].push_back(v);  // u -> v 간선 추가
			id[v]++;  // v의 indegree 증가
			swap(u, v);  // 현재 가수를 다음 가수로 변경
		}
	}

	// indegree가 0인 정점을 큐에 넣음
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (!id[i])
		{
			q.push(i);
		}
	}

	// 위상 정렬 수행
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		sq.push_back(cur);  // 현재 가수를 결과 벡터에 추가

		// 현재 가수와 연결된 모든 가수의 indegree 감소
		for (int nxt : adj[cur])
		{
			if (--id[nxt] == 0) // 위에서 q.pop()된 순간 줄어들었다고 이해하면 서순이해가 편하다.
			{
				q.push(nxt);  // indegree가 0이 되면 큐에 추가
			}
		}
	}

	// 순서 정하기가 불가능한 경우
	if (sq.size() != n)
	{
		cout << 0;
	}
	else
	{
		// 가능한 경우, 순서를 출력
		for (auto s : sq)
		{
			cout << s << ' ';
		}
	}
}
