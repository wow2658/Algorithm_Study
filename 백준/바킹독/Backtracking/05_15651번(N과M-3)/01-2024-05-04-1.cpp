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

	
	for (int i = 1; i <= n; i++)    
	{
		arr[k] = i;
		func(k + 1);
	}

	// 같은 수를 여러 번 골라도 된다 -> isused를 안쓰면서 죄다 다 써버린다.
	// 11 22 33 같은녀석들 추가됨
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	func(0);

}
