#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int num[10];
// 재료를 좁히지않고 중복가능 이니까 no st isused

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[arr[i]] << ' '; // 여기만 특별
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		arr[k] = i;
		func(k + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	func(0);
}