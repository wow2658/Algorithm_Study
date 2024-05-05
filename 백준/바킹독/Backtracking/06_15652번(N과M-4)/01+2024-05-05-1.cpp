#include <iostream>

using namespace std;

int n, m;
int arr[10];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	int st = 1;
	if (k != 0) st = arr[k - 1];
	for (int i = st; i <= n; i++)
	{
		arr[k] = i;
		func(k + 1);
	}

	// 재료를 좁혀간다. -> st쓴다. n과m(2)
	// 중복이 된다.     -> isused안쓴다. n과m(3)
	// 둘을 섞으면 되지 않을까?
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	func(0);

}
