#include <iostream>


using namespace std;

int arr[10];
bool isused[10];


int n, m;

void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (isused[i]) continue;
		arr[cur] = i;
		isused[i] = 1;
		func(cur + 1);
		isused[i] = 0;
	}

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);

}
