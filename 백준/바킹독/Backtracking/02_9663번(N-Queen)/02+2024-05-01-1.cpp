#include <iostream>

using namespace std;

bool isused1[40];
bool isused2[40];
bool isused3[40];

int cnt, n;

void func(int k)
{
	if (k == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)			// 디버깅으로 잡아낸곳. 범위 조심!!
	{
		if (isused1[i] || isused2[k + i] || isused3[k - i + n - 1]) continue;
		isused1[i] = 1;
		isused2[k + i] = 1;
		isused3[k - i + n - 1] = 1;
		func(k + 1);
		isused1[i] = 0;
		isused2[k + i] = 0;
		isused3[k - i + n - 1] = 0;
	}

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << cnt;
}
