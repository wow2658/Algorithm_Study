#include <iostream>

using namespace std;

int n;
int d[1005];

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
		// 가장 최악의 경우를 생각했을때 d[999]+d[998]이면 어마어마하게 커서 오버플로우로 터진다
		// 출력할때가 아니라 여기에서 미리 mod해주자
	}
	cout << d[n];

	return 0;
}