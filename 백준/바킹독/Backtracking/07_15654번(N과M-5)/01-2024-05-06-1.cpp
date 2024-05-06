#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
bool isused[10];
int num[10];      // N과M(1)에서 재료를 커스텀하는 느낌

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[arr[i]] << ' '; // arr[i] 대신에 num[arr[i]] 
		// 
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)         // i=1 ~ n 이 아니다
	{
		if (!isused[i])
		{
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n); // 수 정렬
	func(0);
}