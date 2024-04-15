#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, x;
	priority_queue<int> pq;

	cin >> N;
	while (N--)
	{
		cin >> x;
		if (0 == x)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}

		}
		else
		{
			pq.push(x);
		}
				
	}
	
}