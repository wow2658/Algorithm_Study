#include <bits/stdc++.h>

using namespace std;

int road[100002];
int n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(road, road + 100001, -1);

	cin >> n >> k;
	road[n] = 0;
	queue<int> q;
	q.push(n);


	while (-1 == road[k])
	{
		auto cur = q.front(); q.pop();
		for (auto a : { cur + 1,cur - 1,2 * cur })
		{
			int nxt = a;
			if (nxt < 0 || nxt > 100000) continue;
			if (-1 != road[nxt]) continue;
			q.push(nxt); road[nxt] = road[cur] + 1;
		}
	}

	cout << road[k];


	return 0;
}